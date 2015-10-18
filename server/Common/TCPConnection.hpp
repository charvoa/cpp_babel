//
// TCPConnection.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 14 00:10:50 2015 Nicolas Girardot
// Last update Sun Oct 18 13:48:52 2015 Nicolas Girardot
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

class TCPConnection : public boost::enable_shared_from_this<TCPConnection>
{
private:
  boost::asio::ip::tcp::socket _socket;
  boost::asio::streambuf _response;
  std::string _readMessage;
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

  //Ecriture Async sur le SOCKET


  void start()
  {
    std::string _message = "Bienvenue sur le serveur!";

    boost::asio::async_write(_socket, boost::asio::buffer(_message),
			     boost::bind(&TCPConnection::handleWrite, shared_from_this(),
					 boost::asio::placeholders::error)
			     );
  }

  void	asyncWrite(const std::string &message)
  {
    boost::asio::async_write(_socket,
			     boost::asio::buffer(message),
			     boost::bind(&TCPConnection::handleWrite, shared_from_this(),
					 boost::asio::placeholders::error));
    std::cout << "test" << std::endl;
  }

  void asyncRead()
  {
    boost::asio::async_read(_socket, _response,
			    boost::bind(&TCPConnection::handleRead, shared_from_this(),
					boost::asio::placeholders::error));
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
      {
	asyncRead();
      }
    //SEE WHAT TO DO IN CASE OF ERROR
  }

  void handleRead(const boost::system::error_code& error)
  {
    if (!error)
      {
	asyncRead();
      }
    //CREATE SENDER(RSEPONSE::ERROR)
  }

};

#endif
