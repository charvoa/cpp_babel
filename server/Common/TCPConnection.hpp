//
// TCPConnection.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 14 00:10:50 2015 Nicolas Girardot
// Last update Tue Oct 27 09:52:11 2015 Nicolas Girardot
//

#ifndef TCPCONNECTION_HPP_
#define TCPCONNECTION_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "../VerifyRequest.hh"


class TCPConnection : public boost::enable_shared_from_this<TCPConnection>
{
private:
  boost::asio::ip::tcp::socket _socket;
  std::string _readMessage;
  boost::asio::streambuf _response;

public:
  typedef boost::shared_ptr<TCPConnection> pointer;

  static pointer create(boost::asio::io_service& ios)
  {
    return pointer(new TCPConnection(ios));
  }

  boost::asio::ip::tcp::socket& getSocket()
  {
    return _socket;
  }

  void	asyncWrite(const std::string &message)
  {
    boost::asio::async_write(_socket,
			     boost::asio::buffer(message),
			     boost::bind(&TCPConnection::handleWrite, shared_from_this(),
					 boost::asio::placeholders::error));
  }

  void asyncRead()
  {
    boost::asio::async_read_until(_socket,
				 _response,
				 "\0",
				 boost::bind(&TCPConnection::handleRead,
					     shared_from_this(),
					     boost::asio::placeholders::error)
				 );
  }

  void close()
  {
    _socket.close();
  }

private:

  TCPConnection(boost::asio::io_service &ioS) : _socket(ioS) {}

  void	handleWrite(const boost::system::error_code& error)
  {
    if (!error)
      asyncRead();
  }

  void handleRead(const boost::system::error_code& error)
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

};

#endif
