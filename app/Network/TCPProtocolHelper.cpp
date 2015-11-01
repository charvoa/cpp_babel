//
// TCPProtocolHelper.cpp for TCPProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 27 02:58:48 2015 Antoine Garcia
// Last update Sun Nov  1 06:34:28 2015 Antoine Garcia
//

#include "TCPProtocolHelper.hh"
#include <iostream>

#define BABEL_VERSION "BABEL <1.0>"

TCPProtocolHelper::TCPProtocolHelper()
{
  functions[HANDSHAKE] = &TCPProtocolHelper::createHandshake;
  //handle Methods
  handleFunctions[HANDSHAKE] = &TCPProtocolHelper::handleHandshake;
}

TCPProtocolHelper::~TCPProtocolHelper()
{}

QByteArray	TCPProtocolHelper::createRequest(ProtocolType type)
{
  _ptr = functions[type];
  return (this->*_ptr)();
}

void		TCPProtocolHelper::handleRequest(qint8	type)
{
  (void)type;
  _handlePtr = handleFunctions[HANDSHAKE];
  return (this->*_handlePtr)();
}

//private create Method

QByteArray	TCPProtocolHelper::createHandshake()
{
  std::string str(BABEL_VERSION);
  QByteArray	block;
  QDataStream	out(&block, QIODevice::WriteOnly);

  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(1) << quint16(str.size()); //<< QString(str.c_str());
  out.writeRawData(str.c_str(), str.size());
  return block;
}

QByteArray	TCPProtocolHelper::createLogin()
{
  QByteArray	block;
  QDataStream	out(&block, QIODevice::WriteOnly);
}

//handleRequest	Methods
void	TCPProtocolHelper::handleHandshake()
{
  emit handshakeSuccess();
}
