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

  void	handshake(DataFromClient &fromClient);
  void	signup(DataFromClient &fromClient);
  void	signin(DataFromClient &fromClient);
  void	callRequest(DataFromClient &fromClient);
  void	hangUp(DataFromClient &fromClient);
  void	sendText(DataFromClient &fromClient);
  void	mute(DataFromClient &fromClient);
  void	addParticipantToCall(DataFromClient &fromClient);
  void	sendFile(DataFromClient &fromClient);
  void	pong(DataFromClient &fromClient);
  void	acceptCall(DataFromClient &fromClient);
  void	declineCall(DataFromClient &fromClient);
  void	addContact(DataFromClient &fromClient);
  void	acceptInvitation(DataFromClient &fromClient);
  void	declineInvitation(DataFromClient &fromClient);
  void	modifyStatus(DataFromClient &fromClient);
  void	modifyLogin(DataFromClient &fromClient);
  void	modifyLocation(DataFromClient &fromClient);
  void	addToFavorites(DataFromClient &fromClient);
  void	removeFromFavorites(DataFromClient &fromClient);
  void	addNickname(DataFromClient &fromClient);
  void	removeContact(DataFromClient &fromClient);
  void	modifyProfilePicture(DataFromClient &fromClient);
  void	listenToMail(DataFromClient &fromClient);
  void	success(DataFromClient &fromClient);
  void  error(DataFromClient &fromClient);

  void	initMethod();
  void	methodChecker(DataFromClient &fromClient);

private:
  typedef void(ProtocolClient::*funcs)(DataFromClient &data);
  funcs _ptr;
  typedef std::map<CommunicationClient, funcs>PointersOnFuncs;
  PointersOnFuncs	        _functions;


};

#endif /* !PROTOCOLCLIENT_HH_ */
