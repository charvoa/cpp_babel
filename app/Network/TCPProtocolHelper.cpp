//
// TCPProtocolHelper.cpp for TCPProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 27 02:58:48 2015 Antoine Garcia
// Last update Tue Oct 27 09:46:35 2015 Antoine Garcia
//

#include "TCPProtocolHelper.hh"
#include <iostream>

#define BABEL_VERSION "BABEL <1.0>"

TCPProtocolHelper::TCPProtocolHelper()
{
  functions[HANDSHAKE] = &TCPProtocolHelper::createHandshake;
}

TCPProtocolHelper::~TCPProtocolHelper()
{}

QByteArray&	TCPProtocolHelper::createRequest(ProtocolType type)
{
  _ptr = functions[type];
  return (this->*_ptr)();
}

//private create Method

QByteArray&	TCPProtocolHelper::createHandshake()
{
  std::string str(BABEL_VERSION);
  QByteArray	*block = new QByteArray();
  QDataStream	out(block, QIODevice::WriteOnly);

  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(1) << quint16(str.size()); //<< QString(str.c_str());
  out.writeRawData(str.c_str(), str.size());
  return *block;
}
