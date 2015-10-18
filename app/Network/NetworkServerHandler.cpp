//
// NetworkServerHandler.cpp for NetworkServerHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Oct 18 00:42:17 2015 Antoine Garcia
// Last update Sun Oct 18 11:09:57 2015 Nicolas Charvoz
//

#include "NetworkServerHandler.hh"
#include <QtNetwork>
#include <QTcpSocket>

NetworkServerHandler::NetworkServerHandler(QObject *parent) :parent(parent)
{
  _socket = new QTcpSocket(this);
  connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(_socket, SIGNAL(connected()), this, SLOT(connected()));
}

NetworkServerHandler::~NetworkServerHandler()
{

}

void	NetworkServerHandler::start(const std::string &host, unsigned int port)
{
  _socket->connectToHost(host.c_str(),port);
}

void	NetworkServerHandler::setHost(const std::string &host)
{
  _host = host;
}

void	NetworkServerHandler::setPort(unsigned int port)
{
  _port = port;
}
