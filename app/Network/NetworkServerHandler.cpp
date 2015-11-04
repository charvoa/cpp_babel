//
// NetworkServerHandler.cpp for NetworkServerHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Oct 18 00:42:17 2015 Antoine Garcia
// Last update Mon Nov  2 18:41:42 2015 Nicolas Charvoz
//

#include "NetworkServerHandler.hh"
#include <QtNetwork>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <iostream>
#include <vector>
#define HEADER_LENGTH 3
#define SEPARATOR ";"

NetworkServerHandler::NetworkServerHandler(QObject *parent) :parent(parent)
{
  _socket = new QTcpSocket(this);
  _connected = false;
  connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  connect(_socket, SIGNAL(connected()), this, SLOT(connected()));
  connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connectionError(QAbstractSocket::SocketError)));
  connect(&_request, SIGNAL(handshakeSuccess()), this, SLOT(handshakeSuccess()));
  connect(&_request, SIGNAL(loginSuccess()), this, SLOT (loginSuccess()));
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
  std::cout << "HANDSHAKE" << std::endl;
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
  _read = _socket->readLine();
  _request.handleRequest(_read[0]);
}

void	NetworkServerHandler::connected()
{
  if (_connected == false)
    handShake();
  //emit userConnected(1);
}

void	NetworkServerHandler::connectionError(QAbstractSocket::SocketError)
{
  emit userConnected(0);
}

void	NetworkServerHandler::signUser()
{
  QByteArray	array;
  QDataStream	out(&array, QIODevice::WriteOnly);
  std::string str;

  str += login;
  str += SEPARATOR;
  str += password;
  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(4) << quint32(0) << quint16(str.size() + 2);
  out.writeRawData(str.c_str(), str.size());
  out.writeRawData(";", strlen(";"));
  out << quint8(1);
  _socket->write(array);
}

void	NetworkServerHandler::logUser()
{
  QByteArray	array;
  QDataStream	out(&array, QIODevice::WriteOnly);
  std::string str;
  std::cout << "Log User is being called" << std::endl;
  str += login;
  str += SEPARATOR;
  str += password;
  out.setVersion(QDataStream::Qt_4_3);
  out <<  quint8(5) << quint32(0) << quint16(str.size());
  out.writeRawData(str.c_str(), str.size());
  _socket->write(array);
}

void	NetworkServerHandler::handshakeSuccess()
{
  std::cout << "HANDSHAKE SUCCESS" << std::endl;
  _connected = true;
  emit userConnected(1);
  if (type == 0)
    {
      logUser();
    }
  else {
    signUser();
  }
}

void	NetworkServerHandler::loginSuccess()
{
    emit userConnected(1);
}
