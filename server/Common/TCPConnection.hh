//
// TCPConnection.hh for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Oct 30 14:02:23 2015 Nicolas Girardot
// Last update Fri Oct 30 14:25:37 2015 Nicolas Girardot
//

#ifndef TCPCONNECTION_HH_
#define TCPCONNECTION_HH_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "../VerifyRequest.hh"
#include "../Account.hh"

class TCPConnection : public boost::enable_shared_from_this<TCPConnection>
{
private:
  boost::asio::ip::tcp::socket _socket;
  std::string _readMessage;
  boost::asio::streambuf _response;
  Account *_account = NULL;

public:
  typedef boost::shared_ptr<TCPConnection> pointer;

  static pointer create(boost::asio::io_service&);
  boost::asio::ip::tcp::socket	&getSocket();
  void	asyncWrite(const std::string &);
  void	asyncRead();
  void	close();

private:
  TCPConnection(boost::asio::io_service &ioS);
  void	handleWrite(const boost::system::error_code &);
  void	handleRead(const boost::system::error_code &);
};

#endif
