//
// NetworkClientHandler.cpp for cpp_babel in /home/louis/rendu/cpp_babel/app/Network
//
// Made by Louis Audibert
// Login   <louis@epitech.net>
//
// Started on  Sun Nov  1 04:52:22 2015 Louis Audibert
// Last update Sun Nov  1 18:03:16 2015 Louis Audibert
//

#include "NetworkClientHandler.hh"
#include <QUdpSocket>
#include <QAbstractSocket>
#include <iostream>
#include <vector>

NetworkClientHandler::NetworkClientHandler(QObject *parent) : parent(parent)
{
  std::cout << "Entering NetworkClientHandler constructor" << std::endl;
  _socket = new QUdpSocket(this);
  std::cout << "creating QUDP socket" << std::endl;
  _connected = false;
  _socket->bind(QHostAddress::LocalHost, 1234);
  std::cout << "binding socket" << std::endl;
  connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
  std::cout << "socket connected" << std::endl;
}

NetworkClientHandler::~NetworkClientHandler()
{
  std::cout << "NetworkClientHandler destroyed." << std::endl;
}

void NetworkClientHandler::testUDP(std::string &string)
{
  QByteArray Data;
  Data.append("TEST dialogue udp");
  _socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
  std::cout << "We wrote on UDP socket" << std::endl;
}

void NetworkClientHandler::readyRead()
{
  QByteArray buffer;
  QHostAddress sender;
  quint16 senderPort;

  buffer.resize(_socket->pendingDatagramSize());
  _socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

  qDebug() << "Message from: " << sender.toString();
  qDebug() << "Message port: " << senderPort;
  qDebug() << "Message: " << buffer;
}

int NetworkClientHandler::start(const std::string &host, unsigned int port)
{

}

void NetworkClientHandler::setHost(const std::string &host)
{
  _host = host;
}

void NetworkClientHandler::setPort(unsigned int port)
{
  _port = port;
}

void	NetworkClientHandler::write(const std::string &str)
{
  std::cout << "I SEND" << std::endl;
  _socket->write(str.c_str());
}
