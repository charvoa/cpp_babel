//
// NetworkServerHandler.cpp for NetworkServerHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Oct 18 00:42:17 2015 Antoine Garcia
// Last update Sun Nov  1 05:45:57 2015 Antoine Garcia
//

#include "NetworkServerHandler.hh"
#include <QtNetwork>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <iostream>
#include <vector>
#define HEADER_LENGTH 3

NetworkServerHandler::NetworkServerHandler(QObject *parent) :parent(parent)
{
  _socket = new QTcpSocket(this);
  _connected = false;
  connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(_socket, SIGNAL(connected()), this, SLOT(connected()));
  connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connectionError(QAbstractSocket::SocketError)));
  connect(&_request, SIGNAL(handshakeSuccess()), this, SLOT(handshakeSuccess()));
}

NetworkServerHandler::~NetworkServerHandler()
{

}

int	NetworkServerHandler::start(const std::string &host, unsigned int port)
{
  std::cout << "Connection..." << std::endl;
  _socket->connectToHost(host.c_str(),port);
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

void	NetworkServerHandler::write(const std::string &str)
{
  std::cout << "I SEND" << std::endl;
  _socket->write(str.c_str());
}

void	NetworkServerHandler::handShake()
{
  QByteArray	array =  _request.createRequest(HANDSHAKE);

  _socket->write(array);
}

bool	NetworkServerHandler::getConnectionStatus() const
{
  return (_connected);
}

void	NetworkServerHandler::readyRead()
{
  std::cout << "Is reading" << std::endl;
  QByteArray array = _socket->readLine();
  _request.handleRequest(array[0]);
}

void	NetworkServerHandler::connected()
{
    handShake();
    emit userConnected(1);
}

void	NetworkServerHandler::connectionError(QAbstractSocket::SocketError)
{
  emit userConnected(0);
}

void	NetworkServerHandler::handshakeSuccess()
{
  _connected = true;
}
