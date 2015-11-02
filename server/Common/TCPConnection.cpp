//
// TCPConnection.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 14 00:10:50 2015 Nicolas Girardot
// Last update Mon Nov  2 14:20:42 2015 Nicolas Girardot
//

#include "TCPConnection.hh"
#include "../VerifyRequest.hh"

TCPConnection::pointer TCPConnection::create(boost::asio::io_service& ios)
{
  return pointer(new TCPConnection(ios));
}

boost::asio::ip::tcp::socket& TCPConnection::getSocket()
{
  return _socket;
}

void	TCPConnection::asyncWrite(const std::string &message)
{
  std::cout << "Writing on Socket : " << message << "END OF REQUEST" << std::endl;
  boost::asio::async_write(_socket,
  			   boost::asio::buffer(message),
  			   boost::bind(&TCPConnection::handleWrite, shared_from_this(),
  				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::asyncRead()
{
  boost::asio::async_read_until(_socket,
				_response,
				"\0",
				boost::bind(&TCPConnection::handleRead,
					    shared_from_this(),
					    boost::asio::placeholders::error)
				);
}

void TCPConnection::close()
{
  _socket.close();
}

TCPConnection::TCPConnection(boost::asio::io_service &ioS) : _socket(ioS) {}

void	TCPConnection::handleWrite(const boost::system::error_code& error, std::size_t bytes_transferred)
{
  if (!error)
    asyncRead();
  std::cout << "Bytes Sent : " << bytes_transferred << std::endl;
}

void TCPConnection::handleRead(const boost::system::error_code& error)
{
  if (!error)
    {
      std::bitset<16> b_type;
      std::ostringstream ss;
      std::cout << "Streambuf size is " << _response.size() << std::endl;
      ss << &_response;
      std::string s = ss.str();
      std::cout << "Request is : " << s << "End of Request" << std::endl;
      VerifyRequest *cost = new VerifyRequest(s);
      (void) cost;
      asyncRead();
    }
  else
    {
      _socket.close();
    }
}
