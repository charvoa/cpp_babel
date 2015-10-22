//
// Socket.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 21 15:39:52 2015 Nicolas Girardot
// Last update Wed Oct 21 17:31:34 2015 Nicolas Girardot
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

#include "ISocket.hh"
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

class	Socket : public ISocket
{
public:
  Socket ();

  const boost::asio::ip::tcp::socket &getSocket() const
  {
    return _socket;
  }

  void  setSocket(int soc)
  {
    try
      {
	_socket.assign(boost::asio::ip::tcp::v4(), soc);
      }
    catch(std::exception &e)
      {
	std::cerr << e.what() << std::endl;
      }
  }

private:
  boost::asio::ip::tcp::socket _socket;
};

#endif
