//
// TCPServer.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 22:15:25 2015 Nicolas Girardot
// Last update Wed Oct 21 15:12:45 2015 Nicolas Girardot
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
  TCPConnection::pointer _newConnection;
public:
  TCPServer(boost::asio::io_service& ioService)
    : _acceptor(ioService, tcp::endpoint(tcp::v4(), 4040))
  {
    startAccept();
  }

  void	writeOnServer(const std::string &message)
  {
    _newConnection->asyncWrite(message);
  }

  void readOnServer()
  {
    _newConnection->asyncRead();
  }

private:
  void startAccept()
  {
    _newConnection = TCPConnection::create(_acceptor.get_io_service());
    _acceptor.async_accept(_newConnection->getSocket(),
			   boost::bind(&TCPServer::handleAccept, this, _newConnection,
				       boost::asio::placeholders::error));
  }


  void handleAccept(TCPConnection::pointer newConnection, const boost::system::error_code& error)
  {
    if (!error)
      {
	newConnection->asyncWrite("Welcome to Spyke, a revolutionary way to communicate with your loved ones\n");
	startAccept();
      }
  }
};

#endif
