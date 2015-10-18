//
// NetworkServerHandler.cpp for NetworkServerHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Oct 18 00:42:17 2015 Antoine Garcia
// Last update Sun Oct 18 05:03:27 2015 Antoine Garcia
//

#include "NetworkServerHandler.hh"
#include <QtNetwork>
#include <QTcpSocket>
#include <iostream>
NetworkServerHandler::NetworkServerHandler(QObject *parent) :parent(parent)
{
  _socket = new QTcpSocket(this);
  connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(_socket, SIGNAL(connected()), this, SLOT(connected()));
}

NetworkServerHandler::~NetworkServerHandler()
{

}

int	NetworkServerHandler::start(const std::string &host, unsigned int port)
{
  std::cout << "Connection..." << std::endl;
  _socket->connectToHost(host.c_str(),port);
  if (!_socket->waitForConnected(5000))
    {
      std::cout << "ERROR CONNECTION" << std::endl;
      return (-1);
    }
  std::cout << "connected" << std::endl;
  return (0);
}

void	NetworkServerHandler::setHost(const std::string &host)
{
  _host = host;
}

void	NetworkServerHandler::setPort(unsigned int port)
{
  _port = port;
}

void	NetworkServerHandler::readyRead()
{

}

void	NetworkServerHandler::connected()
{

}
