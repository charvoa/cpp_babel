//
// NetworkServerHandler.cpp for NetworkServerHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Oct 18 00:42:17 2015 Antoine Garcia
// Last update Mon Oct 26 08:40:29 2015 Antoine Garcia
//

#include "NetworkServerHandler.hh"
#include <QtNetwork>
#include <QTcpSocket>
#include <iostream>
#include <vector>
#define HEADER_LENGTH 3

NetworkServerHandler::NetworkServerHandler(QObject *parent) :parent(parent)
{
  _socket = new QTcpSocket(this);
  _connected = false;
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

void	NetworkServerHandler::write(const std::string &str)
{
  std::cout << "I SEND" << std::endl;
  _socket->write(str.c_str());
}

void	NetworkServerHandler::handShake()
{
  std::string str("BABEL <1.0>\n");
  QByteArray	block;
  QDataStream	out(&block, QIODevice::WriteOnly);

  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(1) << quint16(str.size()) << QString(str.c_str());
  _socket->write(block);
}

bool	NetworkServerHandler::getConnectionStatus() const
{
  return (_connected);
}

void	NetworkServerHandler::readyRead()
{
  while (_socket->canReadLine())
    {
      QString line = QString::fromUtf8(_socket->readLine()).trimmed();
      std::cout << line.toUtf8().constData() << std::endl;
    }
}

void	NetworkServerHandler::connected()
{
    handShake();
    emit userConnected(1);
}
