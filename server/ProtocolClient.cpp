#include "ProtocolClient.hh"

bool	ProtocolClient::handshake(Server &server, DataFromClient &data)
{
  std::string handshake = data.data.at(0);
  short version = handshake.substr(handshake.find("<"), handshake.find(">") - handshake.find("<"));

}

bool	ProtocolClient::success(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::error(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::signup(Server &server, DataFromClient &data)
{
  std::string username = data.data.at(0));
  std::string passwd = data.data.at(1);
  short profilePicture = std::to_short(data.data.at(2));
  if (server.isUsernameExisting(username)
    {
      // create error
      return false;
    }
  else
    {
      // create success
      server.addContact(username, passwd, profilePicture);
      return true;
    }
}

bool	ProtocolClient::signin(Server &server, DataFromClient &data)
{
  std::string username = data.data.at(0));
  std::string passwd = data.data.at(1);
  if (server.isUsernameExisting(username) && server.isPasswdCorrectForAccount(username, passwd) && server.getAccountByUsername(username).getStatus == Account::DISCONNECTED)
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

bool	ProtocolClient::callRequest(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::hangUp(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::sendText(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::mute(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::addParticipantToCall(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::sendFile(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::pong(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::acceptCall(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::declineCall(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::addContact(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::modifyStatus(Server &server, DataFromClient &data)
{
  std::string id = data.data.at(0);
  Account::State state = std::to_int(data.data.at(1));
  server.getAccountByID(id).setState(state);
}

bool	ProtocolClient::modifyLogin(Server &server, DataFromClient &data)
{
  std::string id = data.data.at(0);
  std::string newLogin = data.data.at(1);
  if server.isUsernameExisting(newLogin)
    {
      // error
      return false;
    }
  else
  {
    server.getAccountByID(id).setLogin(newLogin);
    return true;
  }
}

bool	ProtocolClient::modifyLocation(Server &server, DataFromClient &data)
{
  std::string id = data.data.at(0);
  std::string newLocation = data.data.at(1);
  server.getAccountByID(id).setLocation(newLocation);
}

bool	ProtocolClient::addToFavorites(Server &server, DataFromClient &data)
{

}

bool	ProtocolClient::addNickname(Server &server, DataFromClient &data)
{
  std::string id = data.data.at(0);
  std::string idNicknamed = data.data.at(1);
  std::string newNickname = data.data.at(2);
  server.getAccountByID(id).getContactByID(idNicknamed).setNickname(newNickname);
}

bool	ProtocolClient::removeContact(Server &server, DataFromClient &data)
{
  server.getAccountByID(data.data.at(0)).removeContact(data.data.at(1));
}

bool	ProtocolClient::modifyProfilPicture(Server &server, DataFromClient &data)
{
  std::string id = data.data.at(0);
  short newProfilePicture = std::to_short(data.data.at(1));
  server.getAccountByID(id).setProfilePicture(newProfilePicture);
}

bool	ProtocolClient::listenToMail(Server &server, DataFromClient &data)
{

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
  _functions[C_MODIFY_STATUS] = &ProtocolClient::modifyStatus;
  _functions[C_MODIFY_LOGIN] = &ProtocolClient::modifyLogin;
  _functions[C_MODIFY_LOCATION] = &ProtocolClient::modifyLocation;
  _functions[C_MUTE] = &ProtocolClient::mute;
  _functions[C_ADD_PARTICIPANT_TO_CALL] = &ProtocolClient::addParticipantToCall;
  _functions[C_ADD_TO_FAVORITES] = &ProtocolClient::addToFavorites;
  _functions[C_ADD_NICKNAME] = &ProtocolClient::addNickname;
  _functions[C_REMOVE_CONTACT] = &ProtocolClient::removeContact;
  _functions[C_MODIFY_PROFIL_PICTURE] = &ProtocolClient::modifyProfilPicture;
  _functions[C_SEND_FILE] = &ProtocolClient::sendFile;
  _functions[C_LISTEN_TO_MAIL] = &ProtocolClient::listenToMail;
}

void ProtocolClient::methodChecker(Server &server, DataFromClient &data)
{
  for (PointersOnFuncs::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if (it->first == _functions[std::distance(_functions.begin(), it)].first)
        (*it)(server, data);
    }
}
