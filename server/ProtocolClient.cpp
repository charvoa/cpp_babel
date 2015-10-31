//
// ProtocolClient.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:19:15 2015 Nicolas Girardot
// Last update Sat Oct 31 16:15:53 2015 Nicolas Girardot
//

#include "ProtocolClient.hh"

ProtocolClient::ProtocolClient()
{

}

ProtocolClient::~ProtocolClient()
{

}

void	ProtocolClient::handshake(Server &server, DataFromClient &fromClient)
{
  std::list<boost::shared_ptr<TCPConnection> >::iterator it;
  it = server.getNetwork()->getServer()->getList()->begin();
  std::string handshake = fromClient.getData().at(0);
  short version = boost::lexical_cast<short>(handshake.substr(handshake.find("<"), handshake.find(">") - handshake.find("<")));
  (*it)->asyncWrite("BITE");
  (void) version;
}

void	ProtocolClient::success(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::error(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::signup(Server &server, DataFromClient &fromClient)
{
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  short profilePicture = boost::lexical_cast<short>(fromClient.getData().at(2));
  if (server.doesUsernameExist(username))
    {
      // create error
        }
  else
    {
      // create success
      server.addAccount(username, passwd, profilePicture);
        }
  (void) profilePicture;
}

void	ProtocolClient::signin(Server &server, DataFromClient &fromClient)
{
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  if (server.doesUsernameExist(username) && server.isPasswdCorrectForAccount(username, passwd) && server.getAccountByUsername(username)->getState() == Account::DISCONNECTED)
    {
      // create success
        }
  else
    {
      // create error
        }
}

void	ProtocolClient::callRequest(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::hangUp(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::sendText(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::mute(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::addParticipantToCall(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::sendFile(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::pong(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::acceptCall(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::declineCall(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::addContact(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string loginAdded = fromClient.getData().at(1);
  (void) server;
}

void	ProtocolClient::acceptInvitation(Server &server, DataFromClient &fromClient)
{
  std::string idReceiverInvitation = fromClient.getData().at(0);
  std::string idSenderInvitation = fromClient.getData().at(1);
  server.getAccountByID(idReceiverInvitation)->addContact(server.getAccountByID(idSenderInvitation));
  server.getAccountByID(idSenderInvitation)->addContact(server.getAccountByID(idReceiverInvitation));
}

void	ProtocolClient::declineInvitation(Server &server, DataFromClient &fromClient)
{
  std::string idReceiverInvitation = fromClient.getData().at(0);
  std::string idSenderInvitation = fromClient.getData().at(1);
  (void) server;
}

void	ProtocolClient::modifyStatus(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  Account::State state = boost::lexical_cast<Account::State>(fromClient.getData().at(1));
  server.getAccountByID(id)->setState(state);
}

void	ProtocolClient::modifyLogin(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string newLogin = fromClient.getData().at(1);
  if (server.doesUsernameExist(newLogin))
    {
      // error
        }
  else
    {
      server.getAccountByID(id)->setLogin(newLogin);
        }
}

void	ProtocolClient::modifyLocation(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string newLocation = fromClient.getData().at(1);
  server.getAccountByID(id)->setLocation(newLocation);
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::addToFavorites(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idFavorited = fromClient.getData().at(1);
  server.getAccountByID(id)->addToFavorite(server.getAccountByID(idFavorited));
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::removeFromFavorites(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idUnfavorited = fromClient.getData().at(1);
  server.getAccountByID(id)->removeFromFavorite(idUnfavorited);
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::addNickname(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idNicknamed = fromClient.getData().at(1);
  std::string newNickname = fromClient.getData().at(2);
  server.getAccountByID(id)->getContactByID(idNicknamed)->setNickname(id, newNickname);
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::removeContact(Server &server, DataFromClient &fromClient)
{
  server.getAccountByID(fromClient.getData().at(0))->removeContact(fromClient.getData().at(1));
  (void) server;
}

void	ProtocolClient::modifyProfilePicture(Server &server, DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  short newProfilePicture = boost::lexical_cast<short>(fromClient.getData().at(1));
  server.getAccountByID(id)->setProfilePicture(newProfilePicture);
  (void) server;
  (void) fromClient;
}

void	ProtocolClient::listenToMail(Server &server, DataFromClient &fromClient)
{
  (void) server;
  (void) fromClient;
}

void ProtocolClient::initMethod()
{
  _functions.insert(std::make_pair(C_HANDSHAKE, &ProtocolClient::handshake));
  _functions.insert(std::make_pair(C_HANDSHAKE, &ProtocolClient::handshake));
  _functions.insert(std::make_pair(C_SUCCESS, &ProtocolClient::success));
  _functions.insert(std::make_pair(C_ERROR, &ProtocolClient::error));
  _functions.insert(std::make_pair(C_SIGNUP, &ProtocolClient::signup));
  _functions.insert(std::make_pair(C_SIGNIN, &ProtocolClient::signin));
  _functions.insert(std::make_pair(C_CALL_REQUEST, &ProtocolClient::callRequest));
  _functions.insert(std::make_pair(C_HANGUP, &ProtocolClient::hangUp));
  _functions.insert(std::make_pair(C_SEND_TEXT, &ProtocolClient::sendText));
  _functions.insert(std::make_pair(C_PONG, &ProtocolClient::pong));
  _functions.insert(std::make_pair(C_ACCEPT_CALL, &ProtocolClient::acceptCall));
  _functions.insert(std::make_pair(C_DECLINE_CALL, &ProtocolClient::declineCall));
  _functions.insert(std::make_pair(C_ADD_CONTACT, &ProtocolClient::addContact));
  _functions.insert(std::make_pair(C_ACCEPT_INVITATION, &ProtocolClient::acceptInvitation));
  _functions.insert(std::make_pair(C_DECLINE_INVITATION, &ProtocolClient::declineInvitation));
  _functions.insert(std::make_pair(C_MODIFY_STATUS, &ProtocolClient::modifyStatus));
  _functions.insert(std::make_pair(C_MODIFY_LOGIN, &ProtocolClient::modifyLogin));
  _functions.insert(std::make_pair(C_MODIFY_LOCATION, &ProtocolClient::modifyLocation));
  _functions.insert(std::make_pair(C_MUTE, &ProtocolClient::mute));
  _functions.insert(std::make_pair(C_ADD_PARTICIPANT_TO_CALL, &ProtocolClient::addParticipantToCall));
  _functions.insert(std::make_pair(C_ADD_TO_FAVORITES, &ProtocolClient::addToFavorites));
  _functions.insert(std::make_pair(C_REMOVE_FROM_FAVORITES, &ProtocolClient::removeFromFavorites));
  _functions.insert(std::make_pair(C_ADD_NICKNAME, &ProtocolClient::addNickname));
  _functions.insert(std::make_pair(C_REMOVE_CONTACT, &ProtocolClient::removeContact));
  _functions.insert(std::make_pair(C_MODIFY_PROFIL_PICTURE, &ProtocolClient::modifyProfilePicture));
  _functions.insert(std::make_pair(C_SEND_FILE, &ProtocolClient::sendFile));
  _functions.insert(std::make_pair(C_LISTEN_TO_MAIL, &ProtocolClient::listenToMail));
}

void ProtocolClient::methodChecker(Server &server, DataFromClient &fromClient)
{
  for (std::map<CommunicationClient, funcs>::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == fromClient.getType())
        (*it)(server, fromClient);
    }
}
