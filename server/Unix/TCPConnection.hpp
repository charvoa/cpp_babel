//
// TCPConnection.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 14 00:10:50 2015 Nicolas Girardot
// Last update Wed Oct 14 00:24:18 2015 Nicolas Girardot
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

using boost::asio::ip::tcp;

class TCPConnection
  : public boost::enable_shared_from_this<TCPConnection>
{
private:
  tcp::socket _socket;
  std::string _message;

public:
  typedef boost::shared_ptr<TCPConnection> pointer;

  static pointer create(boost::asio::io_service& ioService)
  {
    return pointer(new TCPConnection(ioService));
  }

  tcp::socket& getSocket()
  {
    return _socket;
  }

  void	start()
  {
    _message = "Bienvenue sur Mon SERVER BIATCH (ASYNCHRONOUS EN PLUS)";
    boost::asio::async_write(_socket, boost::asio::buffer(_message),
			     boost::bind(&TCPConnection::handleWrite, shared_from_this(),
					 boost::asio::placeholders::error,
					 boost::asio::placeholders::bytes_transferred));
  }

private:
  TCPConnection(boost::asio::io_service& ioService)
    : _socket(ioService)
  {}

  void handleWrite(const boost::system::error_code&, size_t)
  {}
};

#endif
