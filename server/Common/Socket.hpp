//
// Socket.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 21 15:39:52 2015 Nicolas Girardot
// Last update Wed Oct 21 16:13:14 2015 Nicolas Girardot
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

class Socket : public ISocket
{
public:
  boost::asio::ip::tcp::socket &getSocket() const
  {
    return _socket;
  }

  void  setSocket(const boost::asio::ip::tcp::socket &soc)
  {
    _socket = soc;
  }

private:
  boost::asio::ip::tcp::socket _socket;
};

#endif
