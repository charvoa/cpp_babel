//
// TCPProtocolHelper.cpp for TCPProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 27 02:58:48 2015 Antoine Garcia
// Last update Sat Nov  7 07:43:51 2015 Antoine Garcia
//

#include "TCPProtocolHelper.hh"
#include "../User/PTUser.hh"
#include <iostream>

#define BABEL_VERSION "BABEL <1.0>"

TCPProtocolHelper::TCPProtocolHelper()
{
  functions[HANDSHAKE] = &TCPProtocolHelper::createHandshake;
  //handle Methods
  handleFunctions[HANDSHAKESUCCESS] = &TCPProtocolHelper::handleHandshake;
  handleFunctions[SUCCESSLOGIN] = &TCPProtocolHelper::handleLogin;
  handleFunctions[ERRORLOGIN] = &TCPProtocolHelper::errorLogin;
  handleFunctions[ADDCONTACTSUCCESS] = &TCPProtocolHelper::handleContactSuccess;
  //  _clientID = g_PTUser.currentUser().getID();
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
  protocolClient	protocolType = static_cast<protocolClient>(type);
  _handlePtr = handleFunctions[protocolType];
  return (this->*_handlePtr)();
}

void	TCPProtocolHelper::parseLoginSuccess(QByteArray &array)
{
  QDataStream	io(array);
  quint16 sizeData;
  quint8   type;
  quint8   nbContacts;

  //type
  io >> type;
  //sizeData
  io >> sizeData;
  //ClientID
  char	temp[4];
  io.readRawData(temp, 4);
  _clientID.append(temp, 4);
  //nbContacts
  io >> nbContacts;
  if (nbContacts == ';'){
    io >> nbContacts;
    }
  if (nbContacts != 0)
    {
      std::cout << "O CONTACTS" << std::endl;
    }
}

//private create Method

QByteArray	TCPProtocolHelper::createHandshake()
{
  std::string str(BABEL_VERSION);
  QByteArray	block;
  QDataStream	out(&block, QIODevice::WriteOnly);

  out.setVersion(QDataStream::Qt_4_3);
  out << quint8(1) << quint32(0) << quint16(str.size());
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

QByteArray	TCPProtocolHelper::addContactRequest()
{
   QByteArray	array;
  QDataStream	out(&array, QIODevice::WriteOnly);
  std::string str;

  str += c;
  out.setVersion(QDataStream::Qt_4_3);
  out <<  quint8(ADD_CONTACT) << quint32(0) << quint16(str.size());
  out.writeRawData(str.c_str(), str.size());
}

//handleRequest	Methods
void	TCPProtocolHelper::handleHandshake()
{
  emit handshakeSuccess();
}

void	TCPProtocolHelper::handleLogin()
{
  emit	loginSuccess();
}

void	TCPProtocolHelper::errorLogin()
{
  emit loginError();
}

void	TCPProtocolHelper::handleContactSuccess()
{
  emit addContactSuccess();
}
