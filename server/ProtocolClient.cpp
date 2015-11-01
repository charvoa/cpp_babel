B1;3409;0c//
// ProtocolClient.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:19:15 2015 Nicolas Girardot
// Last update Sun Nov  1 17:55:20 2015 Nicolas Girardot
//

#include "ProtocolClient.hh"
#include "Response.hh"
#include "CommunicationEnum.hh"
#include "Sender.hh"

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
  //std::vector<std::string> data;
  //Response *response = new Response(CommunicationServer::S_SUCCESS_HANDSHAKE, (*it), data);
  //  Sender::specialSending(response);

  std::vector<char> std;
  std.push_back(101);
  std.push_back(0);
  std.push_back(0);
  std::string str(std.begin(),std.end());
  (*it)->asyncWrite(str);



//  std::cout << "Length = " << str.length() << std::endl;




}

void	ProtocolClient::success(DataFromClient &fromClient)
{
  (void) fromClient;
}

void	ProtocolClient::error(DataFromClient &fromClient)
{
  (void) fromClient;
}

void  ProtocolClient::affectTCPConnectionToAccountWithUsername(std::string username)
{
  std::list<boost::shared_ptr<TCPConnection> >::iterator it;

  it = g_Server.getNetwork()->getServer()->getList()->begin();
  g_Server.getAccountByUsername(username)->setSocket((*it));
  g_Server.getNetwork()->getServer()->getList()->pop_front();
}

void	ProtocolClient::signup(DataFromClient &fromClient)
{
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  //short profilePicture = boost::lexical_cast<short>(fromClient.getData().at(2));
  if (g_Server.doesUsernameExist(username))
    {
      std::list<boost::shared_ptr<TCPConnection> >::iterator it;
      it = g_Server.getNetwork()->getServer()->getList()->begin();
      std::vector<std::string> data;
      Response *response = new Response(CommunicationServer::S_ERROR_SIGN, (*it), data);
      Sender::specialSending(response);
    }
  else
    {
      g_Server.addAccount(username, passwd, 1);
      g_Server.getAccountByUsername(username)->getFormatedContactList();
      this->affectTCPConnectionToAccountWithUsername(username);
    }
  std::cout << "Working Server Account" << std::endl;
}

void	ProtocolClient::signin(DataFromClient &fromClient)
{
  std::string username = fromClient.getData().at(0);
  std::string passwd = fromClient.getData().at(1);
  if (g_Server.doesUsernameExist(username) && g_Server.isPasswdCorrectForAccount(username, passwd) && g_Server.getAccountByUsername(username)->getState() == Account::DISCONNECTED)
    {
      g_Server.getAccountByUsername(username)->getFormatedContactList();
      this->affectTCPConnectionToAccountWithUsername(username);
    }
  else
    {
      g_Server.getNetwork()->getServer()->getList()->pop_front();
      std::cout << "Username does not exist" << std::endl;
      // create error
    }
}

void	ProtocolClient::callRequest(DataFromClient &fromClient)
{
  std::vector<std::string> data;

  std::string sender = fromClient.getClientID();
  std::string receiver = fromClient.getData().at(0);
  std::string ip = g_Server.getAccountByID(sender)->getSocket()->getSocket().remote_endpoint().address().to_string();
  std::vector<std::string> ipVector;
  boost::split(ipVector, ip, boost::is_any_of("."));
  std::string ipWithoutDot;

  for (std::vector<std::string>::iterator it = ipVector.begin(); it != ipVector.end(); ++it)
    {
      ipWithoutDot.push_back(boost::lexical_cast<char>(std::stoi(*it)));
    }

  data.push_back(fromClient.getClientID());
  data.push_back(ipWithoutDot); // ip.sender

  Response *response = new Response(CommunicationServer::S_CONTACT_REQUEST, g_Server.getAccountByID(receiver), data);
  Sender::send(response);
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
}

void	ProtocolClient::addToFavorites(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idFavorited = fromClient.getData().at(1);
  g_Server.getAccountByID(id)->addToFavorite(g_Server.getAccountByID(idFavorited));
}

void	ProtocolClient::removeFromFavorites(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idUnfavorited = fromClient.getData().at(1);
  g_Server.getAccountByID(id)->removeFromFavorite(idUnfavorited);
}

void	ProtocolClient::addNickname(DataFromClient &fromClient)
{
  std::string id = fromClient.getData().at(0);
  std::string idNicknamed = fromClient.getData().at(1);
  std::string newNickname = fromClient.getData().at(2);
  g_Server.getAccountByID(id)->getContactByID(idNicknamed)->setNickname(id, newNickname);
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
