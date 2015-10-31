//
// ProtocolServer.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:51:03 2015 Serge Heitzler
// Last update Sat Oct 31 21:08:53 2015 Serge Heitzler
//

#include "ProtocolServer.hh"

ProtocolServer::ProtocolServer()
{

}

ProtocolServer::~ProtocolServer()
{

}

bool	ProtocolServer::successHandshake(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::successOnSign(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::errorUnknown(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::errorSign(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::errorCall(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::errorNotImplemented(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::ping(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::contactList(Server &server, DataToClient &toData)
{
  
}

bool	ProtocolServer::contactInfo(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::contactRequest(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::callRequest(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::sendText(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::hangedUp(Server &server, DataToClient &toData)
{

}

bool	ProtocolServer::sendFile(Server &server, DataToClient &toData)
{

}

void ProtocolServer::initMethod()
{
  _functions.insert(std::make_pair(S_SUCCESS_HANDSHAKE, &ProtocolServer::successHandshake));
  _functions.insert(std::make_pair(S_SUCCESS_ON_SIGN, &ProtocolServer::successOnSign));
  _functions.insert(std::make_pair(S_ERROR_UNKNOWN, &ProtocolServer::errorUnknown));
  _functions.insert(std::make_pair(S_ERROR_SIGN, &ProtocolServer::errorSign));
  _functions.insert(std::make_pair(S_ERROR_CALL, &ProtocolServer::errorCall));
  _functions.insert(std::make_pair(S_ERROR_NOT_IMPLEMENTED, &ProtocolServer::errorNotImplemented));
  _functions.insert(std::make_pair(S_PING, &ProtocolServer::ping));
  _functions.insert(std::make_pair(S_CONTACT_LIST, &ProtocolServer::contactList));
  _functions.insert(std::make_pair(S_CONTACT_INFO, &ProtocolServer::contactInfo));
  _functions.insert(std::make_pair(S_CONTACT_REQUEST, &ProtocolServer::contactRequest));
  _functions.insert(std::make_pair(S_CALL_REQUEST, &ProtocolServer::callRequest));
  _functions.insert(std::make_pair(S_SEND_TEXT, &ProtocolServer::sendText));
  _functions.insert(std::make_pair(S_HANGED_UP, &ProtocolServer::hangedUp));
  _functions.insert(std::make_pair(S_SEND_FILE, &ProtocolServer::sendFile));
}

void ProtocolServer::methodChecker(Server &server, DataToClient &toData)
{
  for (PointersOnFuncs::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if ((*it)->first == toData.getType())
        (*it)(server, toData);
    }
}
