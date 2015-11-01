//
// ProtocolClient.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:19:15 2015 Nicolas Girardot
// Last update Sun Nov  1 13:45:37 2015 Nicolas Girardot
//

#include "ProtocolClient.hh"

ProtocolClient::ProtocolClient()
{
  initMethod();
}

ProtocolClient::~ProtocolClient()
{

}

void	ProtocolClient::handshake(DataFromClient &fromClient)
{
  std::list<boost::shared_ptr<TCPConnection> >::iterator it;
  it = g_Server.getNetwork()->getServer()->getList()->begin();
  std::string handshake = fromClient.getData().at(0);
  //short version = boost::lexical_cast<short>(handshake.substr(handshake.find("<"), handshake.find(">") - handshake.find("<")));
  std::vector<char> std;
  std.push_back(101);
  std.push_back(0);
  std.push_back(0);
  std::string str(std.begin(),std.end());
  std::cout << "Length = " << str.length() << std::endl;
  (*it)->asyncWrite(str);
}

void	ProtocolClient::success(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::error(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::signup(DataFromClient &fromClient)
{
  std::list<boost::shared_ptr<TCPConnection> >::iterator it;
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  short profilePicture = boost::lexical_cast<short>(fromClient.getData().at(2));
  if (g_Server.doesUsernameExist(username))
    {
      // create error
        }
  else
    {
      // create success
      it = g_Server.getNetwork()->getServer()->getList()->begin();
      g_Server.getAccountByUsername(username)->setSocket((*it));
      g_Server.getNetwork()->getServer()->getList()->pop_front();



      g_Server.addAccount(username, passwd, profilePicture);
        }
  (void) profilePicture;
}

void	ProtocolClient::signin(DataFromClient &fromClient)
{
  std::list<boost::shared_ptr<TCPConnection> >::iterator it;
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  if (g_Server.doesUsernameExist(username) && g_Server.isPasswdCorrectForAccount(username, passwd) && g_Server.getAccountByUsername(username)->getState() == Account::DISCONNECTED)
    {
      // create success
      it = g_Server.getNetwork()->getServer()->getList()->begin();
      g_Server.getAccountByUsername(username)->setSocket((*it));
      g_Server.getNetwork()->getServer()->getList()->pop_front();



      g_Server.getAccountByUsername(username)->getFormatedContactList();
    }
  else
    {
      // create error
    }
}

void	ProtocolClient::callRequest(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::hangUp(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::sendText(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::mute(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::addParticipantToCall(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::sendFile(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::pong(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::acceptCall(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::declineCall(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::addContact(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string loginAdded = fromClient.getData().at(1);
}

void	ProtocolClient::acceptInvitation(DataFromClient &fromClient)
{
  std::string idReceiverInvitation = fromClient.getData().at(0);
  std::string idSenderInvitation = fromClient.getData().at(1);
  g_Server.getAccountByID(idReceiverInvitation)->addContact(g_Server.getAccountByID(idSenderInvitation));
  g_Server.getAccountByID(idSenderInvitation)->addContact(g_Server.getAccountByID(idReceiverInvitation));
}

void	ProtocolClient::declineInvitation(DataFromClient &fromClient)
{
  std::string idReceiverInvitation = fromClient.getData().at(0);
  std::string idSenderInvitation = fromClient.getData().at(1);
}

void	ProtocolClient::modifyStatus(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  //Account::State state = (fromClient.getData().at(1));

  //g_Server.getAccountByID(id)->setState(state);
}

void	ProtocolClient::modifyLogin(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string newLogin = fromClient.getData().at(1);
  if (g_Server.doesUsernameExist(newLogin))
    {
      // error
        }
  else
    {
      g_Server.getAccountByID(id)->setLogin(newLogin);
    }
}

void	ProtocolClient::modifyLocation(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string newLocation = fromClient.getData().at(1);
  g_Server.getAccountByID(id)->setLocation(newLocation);
  (void) fromClient;
}

void	ProtocolClient::addToFavorites(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idFavorited = fromClient.getData().at(1);
  g_Server.getAccountByID(id)->addToFavorite(g_Server.getAccountByID(idFavorited));
  (void) fromClient;
}

void	ProtocolClient::removeFromFavorites(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idUnfavorited = fromClient.getData().at(1);
  g_Server.getAccountByID(id)->removeFromFavorite(idUnfavorited);
  (void) fromClient;
}

void	ProtocolClient::addNickname(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idNicknamed = fromClient.getData().at(1);
  std::string newNickname = fromClient.getData().at(2);
  g_Server.getAccountByID(id)->getContactByID(idNicknamed)->setNickname(id, newNickname);
  (void) fromClient;
}

void	ProtocolClient::removeContact(DataFromClient &fromClient)
{
  g_Server.getAccountByID(fromClient.getData().at(0))->removeContact(fromClient.getData().at(1));
}

void	ProtocolClient::modifyProfilePicture(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  short newProfilePicture = boost::lexical_cast<short>(fromClient.getData().at(1));
  g_Server.getAccountByID(id)->setProfilePicture(newProfilePicture);
  (void) fromClient;
}

void	ProtocolClient::listenToMail(DataFromClient &fromClient)
{
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

void ProtocolClient::methodChecker(DataFromClient &fromClient)
{
  for (std::map<CommunicationClient, funcs>::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == fromClient.getType())
	(*this.*_functions[fromClient.getType()])(fromClient);
    }
}
