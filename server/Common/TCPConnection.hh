//
// TCPConnection.hh for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Oct 30 14:02:23 2015 Nicolas Girardot
// Last update Sat Oct 31 21:42:55 2015 Nicolas Girardot
//

#ifndef TCPCONNECTION_HH
#define TCPCONNECTION_HH

#include <ctime>
#include <bitset>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "../Account.hh"

class Account;

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
