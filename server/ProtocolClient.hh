//
// ProtocolClient.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Oct 31 11:51:56 2015 Nicolas Girardot
// Last update Sat Oct 31 21:25:40 2015 Nicolas Girardot
//

#ifndef _PROTOCOLCLIENT_HH
# define _PROTOCOLCLIENT_HH

#include <string>
#include <boost/lexical_cast.hpp>
#include "DataFromClient.hh"
#include "Server.hh"
# include "CommunicationEnum.hh"

class			DataFromClient;

class		        ProtocolClient
{
public:
  ProtocolClient();
  ~ProtocolClient();

  void	handshake(Server &server, DataFromClient &fromClient);
  void	signup(Server &server, DataFromClient &fromClient);
  void	signin(Server &server, DataFromClient &fromClient);
  void	callRequest(Server &server, DataFromClient &fromClient);
  void	hangUp(Server &server, DataFromClient &fromClient);
  void	sendText(Server &server, DataFromClient &fromClient);
  void	mute(Server &server, DataFromClient &fromClient);
  void	addParticipantToCall(Server &server, DataFromClient &fromClient);
  void	sendFile(Server &server, DataFromClient &fromClient);
  void	pong(Server &server, DataFromClient &fromClient);
  void	acceptCall(Server &server, DataFromClient &fromClient);
  void	declineCall(Server &server, DataFromClient &fromClient);
  void	addContact(Server &server, DataFromClient &fromClient);
  void	acceptInvitation(Server &server, DataFromClient &fromClient);
  void	declineInvitation(Server &server, DataFromClient &fromClient);
  void	modifyStatus(Server &server, DataFromClient &fromClient);
  void	modifyLogin(Server &server, DataFromClient &fromClient);
  void	modifyLocation(Server &server, DataFromClient &fromClient);
  void	addToFavorites(Server &server, DataFromClient &fromClient);
  void	removeFromFavorites(Server &server, DataFromClient &fromClient);
  void	addNickname(Server &server, DataFromClient &fromClient);
  void	removeContact(Server &server, DataFromClient &fromClient);
  void	modifyProfilePicture(Server &server, DataFromClient &fromClient);
  void	listenToMail(Server &server, DataFromClient &fromClient);
  void	success(Server &server, DataFromClient &fromClient);
  void  error(Server &server, DataFromClient &fromClient);

  void	initMethod();
  void	methodChecker(Server &server, DataFromClient &fromClient);

private:
  typedef void(ProtocolClient::*funcs)(Server &server, DataFromClient &data);
  funcs _ptr;
  typedef std::map<CommunicationClient, funcs>PointersOnFuncs;
  PointersOnFuncs	        _functions;


};

#endif /* !PROTOCOLCLIENT_HH_ */
