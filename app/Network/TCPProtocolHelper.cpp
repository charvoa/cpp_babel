//
// TCPProtocolHelper.cpp for TCPProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 27 02:58:48 2015 Antoine Garcia
// Last update Sun Nov  1 07:37:08 2015 Antoine Garcia
//

#include "TCPProtocolHelper.hh"
#include "../User/PTUser.hh"
#include <iostream>

#define BABEL_VERSION "BABEL <1.0>"

TCPProtocolHelper::TCPProtocolHelper()
{
  functions[HANDSHAKE] = &TCPProtocolHelper::createHandshake;
  //handle Methods
  handleFunctions[HANDSHAKE] = &TCPProtocolHelper::handleHandshake;
  //  _clientID = g_PTUser.currentUser().getID();
  _clientID = 4;
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
  out << quint8(1) << quint16(str.size());
  out.writeRawData(str.c_str(), str.size());
  return block;
}

QByteArray	TCPProtocolHelper::createCallRequest()
{
  QByteArray	block;
  QDataStream	out(&block, QIODevice::WriteOnly);

  /* A CHANGER PAR UN VRAI RECEIVER ID */
  int receiverID = 4;
  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(6) << _clientID << 4 << receiverID;
  return block;
}

QByteArray	TCPProtocolHelper::acceptCallRequest()
{
  QByteArray	block;
  QDataStream	out(&block, QIODevice::WriteOnly);

  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(7) << _clientID << 8 << "" ; //<< g_PTUser.currentUser().getIP();
  return block;
}

//handleRequest	Methods
void	TCPProtocolHelper::handleHandshake()
{
  emit handshakeSuccess();
}
