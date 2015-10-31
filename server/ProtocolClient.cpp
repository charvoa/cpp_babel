//
// ProtocolClient.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:19:15 2015 Nicolas Girardot
// Last update Sat Oct 31 14:17:26 2015 Nicolas Girardot
//

#include "ProtocolClient.hh"

ProtocolClient::ProtocolClient()
{

}

ProtocolClient::~ProtocolClient()
{

}

bool	ProtocolClient::handshake(Server &server, DataFromClient &fromClient)
{
  std::list<boost::shared_ptr<TCPConnection> >::iterator it;
  it = server.getNetwork()->getServer()->getList()->begin();
  std::string handshake = fromClient.getData().at(0);
  short version = boost::lexical_cast<short>(handshake.substr(handshake.find("<"), handshake.find(">") - handshake.find("<")));
  (*it)->asyncWrite("BITE");
  (void) version;
  return true;
}

bool	ProtocolClient::success(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::error(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::signup(Server &server, DataFromClient &fromClient)
{
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  short profilePicture = boost::lexical_cast<short>(fromClient.getData().at(2));
  if (server.doesUsernameExist(username))
    {
      // create error
      return false;
    }
  else
    {
      // create success
      server.addAccount(username, passwd, profilePicture);
      return true;
    }
  (void) profilePicture;
}

bool	ProtocolClient::signin(Server &server, DataFromClient &fromClient)
{
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  if (server.doesUsernameExist(username) && server.isPasswdCorrectForAccount(username, passwd) && server.getAccountByUsername(username)->getState() == Account::DISCONNECTED)
    {
      // create success
      return true;
    }
  else
    {
      // create error
      return false;
    }
}

bool	ProtocolClient::callRequest(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::hangUp(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::sendText(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::mute(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::addParticipantToCall(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::sendFile(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::pong(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::acceptCall(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::declineCall(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::addContact(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string loginAdded = fromClient.getData().at(1);
  (void) server;
  return false;
}

bool	ProtocolClient::acceptInvitation(Server &server, DataFromClient &fromClient)
{
  std::string idReceiverInvitation = fromClient.getData().at(0);
  std::string idSenderInvitation = fromClient.getData().at(1);
  server.getAccountByID(idReceiverInvitation)->addContact(server.getAccountByID(idSenderInvitation));
  server.getAccountByID(idSenderInvitation)->addContact(server.getAccountByID(idReceiverInvitation));
  return true;
}

bool	ProtocolClient::declineInvitation(Server &server, DataFromClient &fromClient)
{
  std::string idReceiverInvitation = fromClient.getData().at(0);
  std::string idSenderInvitation = fromClient.getData().at(1);
  (void) server;
  return (false);
}

bool	ProtocolClient::modifyStatus(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  Account::State state = boost::lexical_cast<Account::State>(fromClient.getData().at(1));
  server.getAccountByID(id)->setState(state);
  return false;
}

bool	ProtocolClient::modifyLogin(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string newLogin = fromClient.getData().at(1);
  if (server.doesUsernameExist(newLogin))
    {
      // error
      return false;
    }
  else
    {
      server.getAccountByID(id)->setLogin(newLogin);
      return true;
    }
}

bool	ProtocolClient::modifyLocation(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string newLocation = fromClient.getData().at(1);
  server.getAccountByID(id)->setLocation(newLocation);
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::addToFavorites(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idFavorited = fromClient.getData().at(1);
  server.getAccountByID(id)->addToFavorite(server.getAccountByID(idFavorited));
  (void) server;
  (void) fromClient;
  return true;
}

bool	ProtocolClient::removeFromFavorites(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idUnfavorited = fromClient.getData().at(1);
  server.getAccountByID(id)->removeFromFavorite(idUnfavorited);
  (void) server;
  (void) fromClient;
  return true;
}

bool	ProtocolClient::addNickname(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idNicknamed = fromClient.getData().at(1);
  std::string newNickname = fromClient.getData().at(2);
  server.getAccountByID(id)->getContactByID(idNicknamed)->setNickname(id, newNickname);
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::removeContact(Server &server, DataFromClient &fromClient)
{
  server.getAccountByID(fromClient.getData().at(0))->removeContact(fromClient.getData.at(1));
  (void) server;
  return true;
}

bool	ProtocolClient::modifyProfilePicture(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  short newProfilePicture = boost::lexical_cast<short>(fromClient.getData().at(1));
  server.getAccountByID(id)->setProfilePicture(newProfilePicture);
  (void) server;
  (void) fromClient;
  return false;
}

bool	ProtocolClient::listenToMail(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
  return false;
}

void ProtocolClient::initMethod()
{
  _functions[C_HANDSHAKE] = &ProtocolClient::handshake;
  _functions[C_SUCCESS] = &ProtocolClient::success;
  _functions[C_ERROR] = &ProtocolClient::error;
  _functions[C_SIGNUP] = &ProtocolClient::signup;
  _functions[C_SIGNIN] = &ProtocolClient::signin;
  _functions[C_CALL_REQUEST] = &ProtocolClient::callRequest;
  _functions[C_HANGUP] = &ProtocolClient::hangUp;
  _functions[C_SENDTEXT] = &ProtocolClient::sendText;
  _functions[C_PONG] = &ProtocolClient::pong;
  _functions[C_ACCEPT_CALL] = &ProtocolClient::acceptCall;
  _functions[C_DECLINE_CALL] = &ProtocolClient::declineCall;
  _functions[C_ADD_CONTACT] = &ProtocolClient::addContact;
  _functions[C_ACCEPT_INVITATION] = &ProtocolClient::acceptInvitation;
  _functions[C_DECLINE_INVITATION] = &ProtocolClient::declineInvitation;
  _functions[C_MODIFY_STATUS] = &ProtocolClient::modifyStatus;
  _functions[C_MODIFY_LOGIN] = &ProtocolClient::modifyLogin;
  _functions[C_MODIFY_LOCATION] = &ProtocolClient::modifyLocation;
  _functions[C_MUTE] = &ProtocolClient::mute;
  _functions[C_ADD_PARTICIPANT_TO_CALL] = &ProtocolClient::addParticipantToCall;
  _functions[C_ADD_TO_FAVORITES] = &ProtocolClient::addToFavorites;
  _functions[C_REMOVE_FROM_FAVORITES] = &ProtocolClient::removeFromFavorites;
  _functions[C_ADD_NICKNAME] = &ProtocolClient::addNickname;
  _functions[C_REMOVE_CONTACT] = &ProtocolClient::removeContact;
  _functions[C_MODIFY_PROFIL_PICTURE] = &ProtocolClient::modifyProfilePicture;
  _functions[C_SEND_FILE] = &ProtocolClient::sendFile;
  _functions[C_LISTEN_TO_MAIL] = &ProtocolClient::listenToMail;
}

void ProtocolClient::methodChecker(Server &server, DataFromClient &fromClient)
{
  for (::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if ((*it)->first == _functions(std::distance(_functions.begin(), (*it))].first)
        (*it)(server, fromClient);
    }
}
