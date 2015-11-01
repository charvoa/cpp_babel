//
// TCPServer.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 22:15:25 2015 Nicolas Girardot
// Last update Sun Nov  1 13:43:50 2015 Nicolas Girardot
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
#include <list>
#include "TCPConnection.hh"

using boost::asio::ip::tcp;

class TCPServer
{
private:
  tcp::acceptor _acceptor;
  TCPConnection::pointer _newConnection;
  std::list<TCPConnection::pointer> _TCPList;
public:
  TCPServer(boost::asio::io_service& ioService)
    : _acceptor(ioService, tcp::endpoint(tcp::v4(), 4040))
  {
    startAccept();
  }

  void writeOnServer(const std::string &message)
  {
    _newConnection->asyncWrite(message);
  }

  void readOnServer()
  {
    _newConnection->asyncRead();
  }

  std::list<TCPConnection::pointer> *getList()
  {
    return (&_TCPList);
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
    std::cout << "I'm working 50/100" << std::endl;
    if (!error)
      {
	std::cout << "Im working biatch" << std::endl;
	_TCPList.push_back(newConnection);
	newConnection->asyncRead();
	startAccept();
      }
    std::cout << "Error is " << error.message() << std::endl;
  }
};

#endif
