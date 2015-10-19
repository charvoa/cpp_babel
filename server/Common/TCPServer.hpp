//
// TCPServer.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 22:15:25 2015 Nicolas Girardot
// Last update Sun Oct 18 14:53:54 2015 Nicolas Girardot
//

#ifndef TCPSERVER_HPP_
#define TCPSERVER_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "TCPConnection.hpp"

using boost::asio::ip::tcp;

class TCPServer
{
private:
  tcp::acceptor _acceptor;

public:
  TCPServer(boost::asio::io_service& ioService)
    : _acceptor(ioService, tcp::endpoint(tcp::v4(), 4040))
  {
    startAccept();
  }

private:
  void startAccept()
  {
    TCPConnection::pointer newConnection =
      TCPConnection::create(_acceptor.get_io_service());
    _acceptor.async_accept(newConnection->getSocket(),
			   boost::bind(&TCPServer::handleAccept, this, newConnection,
				       boost::asio::placeholders::error));
  }

  void handleAccept(TCPConnection::pointer newConnection, const boost::system::error_code& error)
  {
    if (!error)
      {
	newConnection->asyncWrite("JIOLE");
	startAccept();
      }
  }
};

#endif
