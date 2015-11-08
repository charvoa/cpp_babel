//
// TCPProtocolHelper.cpp for TCPProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 27 02:58:48 2015 Antoine Garcia
// Last update Sun Nov  8 19:06:31 2015 Nicolas Charvoz
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
  handleFunctions[CALLING] = &TCPProtocolHelper::handleCall;
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
  QByteArray	bufferData;
  int	i = 0;

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
  char	*data = (char*)malloc(sizeData * sizeof(char));
  if (nbContacts == ';'){
    io >> nbContacts;
    }
  io.readRawData(data, sizeData);
  bufferData.append(data, sizeData);
  if (nbContacts != 0)
    {
      int	start = 2;
      std::cout << "I HAVE CONTACT" << (int)nbContacts << std::endl;
      QList<QByteArray> token = bufferData.split(';');
      while (i < nbContacts)
	{
	  std::string username = token[start].constData();
	  start++;
	  std::string location = token[start].constData();
	  start++;
	  std::string status = token[start].constData();
	  start++;
	  std::string profilePicture  = token[start].constData();
	  std::cout << "id pic : " << profilePicture << std::endl;
	  Contact	contact(username, location, 1, atoi(profilePicture.c_str())
				, 0);
	  g_PTUser.currentUser().addContact(contact);
	  start += 3;
	  i++;
	}
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

void	TCPProtocolHelper::handleCall()
{
  emit receiveCall();
}
