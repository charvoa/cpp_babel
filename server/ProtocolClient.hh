//
// ProtocolClient.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Oct 31 11:51:56 2015 Nicolas Girardot
// Last update Sat Oct 31 14:17:10 2015 Nicolas Girardot
//

#ifndef _PROTOCOLCLIENT_HH
# define _PROTOCOLCLIENT_HH

#include <string>
#include <boost/lexical_cast.hpp>
#include "DataFromClient.hh"
#include "Server.hh"
#include "AProtocol.hh"

class		        ProtocolClient : public AProtocol
{
public:
  ProtocolClient();
  ~ProtocolClient();

private:

  bool	handshake(Server &server, DataFromClient &fromClient);
  bool	signup(Server &server, DataFromClient &fromClient);
  bool	signin(Server &server, DataFromClient &fromClient);
  bool	callRequest(Server &server, DataFromClient &fromClient);
  bool	hangUp(Server &server, DataFromClient &fromClient);
  bool	sendText(Server &server, DataFromClient &fromClient);
  bool	mute(Server &server, DataFromClient &fromClient);
  bool	addParticipantToCall(Server &server, DataFromClient &fromClient);
  bool	sendFile(Server &server, DataFromClient &fromClient);
  bool	pong(Server &server, DataFromClient &fromClient);
  bool	acceptCall(Server &server, DataFromClient &fromClient);
  bool	declineCall(Server &server, DataFromClient &fromClient);
  bool	addContact(Server &server, DataFromClient &fromClient);
  bool	acceptInvitation(Server &server, DataFromClient &fromClient);
  bool	declineInvitation(Server &server, DataFromClient &fromClient);
  bool	modifyStatus(Server &server, DataFromClient &fromClient);
  bool	modifyLogin(Server &server, DataFromClient &fromClient);
  bool	modifyLocation(Server &server, DataFromClient &fromClient);
  bool	addToFavorites(Server &server, DataFromClient &fromClient);
  bool	removeFromFavorites(Server &server, DataFromClient &fromClient);
  bool	addNickname(Server &server, DataFromClient &fromClient);
  bool	removeContact(Server &server, DataFromClient &fromClient);
  bool	modifyProfilePicture(Server &server, DataFromClient &fromClient);
  bool	listenToMail(Server &server, DataFromClient &fromClient);
  bool	success(Server &server, DataFromClient &fromClient);
  bool  error(Server &server, DataFromClient &fromClient);

  void	initMethod();
  void	methodChecker(Server &server, DataFromClient &fromClient);
};

#endif /* !PROTOCOLCLIENT_HH_ */
