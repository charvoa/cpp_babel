#ifndef _PROTOCOLCLIENT_HH
# define _PROTOCOLCLIENT_HH

#include <string>
#include "DataFromClient.hh"

class		        ProtocolClient : public AProcotol
{

  ProtocolClient();
  ~ProtocolClient();

private:

  bool	handshake(Server &server, DataFromClient &fromClient);
  bool	signup(Server &server, DataFromClient &fromClient);
  bool	signin(Server &server, DataFromClient &fromClient);
  bool	callRequest(Server &server, DataFromClient &fromClient);
  bool	sendText(Server &server, DataFromClient &fromClient);
  bool	mute(Server &server, DataFromClient &fromClient);
  bool	addParticipantToCall(Server &server, DataFromClient &fromClient);
  bool	sendFile(Server &server, DataFromClient &fromClient);
  bool	pong(Server &server, DataFromClient &fromClient);
  bool	acceptCall(Server &server, DataFromClient &fromClient);
  bool	declineCall(Server &server, DataFromClient &fromClient);
  bool	addContact(Server &server, DataFromClient &fromClient);
  bool	modifyStatus(Server &server, DataFromClient &fromClient);
  bool	modifyLogin(Server &server, DataFromClient &fromClient);
  bool	modifyLocation(Server &server, DataFromClient &fromClient);
  bool	addToFavorites(Server &server, DataFromClient &fromClient);
  bool	removeFromFavorites(Server &server, DataFromClient &fromClient);
  bool	addNickname(Server &server, DataFromClient &fromClient);
  bool	removeContact(Server &server, DataFromClient &fromClient);
  bool	modifyProfilePicture(Server &server, DataFromClient &fromClient);
  bool	listenToMail(Server &server, DataFromClient &fromClient);

};

#endif /* !PROTOCOLCLIENT_HH_ */
