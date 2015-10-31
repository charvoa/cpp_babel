//
// ProtocolServer.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:51:03 2015 Serge Heitzler
// Last update Sat Oct 31 22:09:27 2015 Serge Heitzler
//

#include "ProtocolServer.hh"

ProtocolServer::ProtocolServer()
{

}

ProtocolServer::~ProtocolServer()
{

}

static bool	ProtocolServer::successHandshake(DataToClient &toData)
{

}

static bool	ProtocolServer::successOnSign(DataToClient &toData)
{

}

static bool	ProtocolServer::errorUnknown(DataToClient &toData)
{

}

static bool	ProtocolServer::errorSign(DataToClient &toData)
{

}

static bool	ProtocolServer::errorCall(DataToClient &toData)
{

}

static bool	ProtocolServer::errorNotImplemented(DataToClient &toData)
{

}

static bool	ProtocolServer::ping(DataToClient &toData)
{

}

static bool	ProtocolServer::contactList(DataToClient &toData)
{

}

static bool	ProtocolServer::contactInfo(DataToClient &toData)
{

}

static bool	ProtocolServer::contactRequest(DataToClient &toData)
{

}

static bool	ProtocolServer::callRequest(DataToClient &toData)
{

}

static bool	ProtocolServer::sendText(DataToClient &toData)
{

}

static bool	ProtocolServer::hangedUp(DataToClient &toData)
{

}

static bool	ProtocolServer::sendFile(DataToClient &toData)
{

}

// void ProtocolServer::initMethod()
// {
//   _functions.insert(std::make_pair(S_SUCCESS_HANDSHAKE, &ProtocolServer::successHandshake));
//   _functions.insert(std::make_pair(S_SUCCESS_ON_SIGN, &ProtocolServer::successOnSign));
//   _functions.insert(std::make_pair(S_ERROR_UNKNOWN, &ProtocolServer::errorUnknown));
//   _functions.insert(std::make_pair(S_ERROR_SIGN, &ProtocolServer::errorSign));
//   _functions.insert(std::make_pair(S_ERROR_CALL, &ProtocolServer::errorCall));
//   _functions.insert(std::make_pair(S_ERROR_NOT_IMPLEMENTED, &ProtocolServer::errorNotImplemented));
//   _functions.insert(std::make_pair(S_PING, &ProtocolServer::ping));
//   _functions.insert(std::make_pair(S_CONTACT_LIST, &ProtocolServer::contactList));
//   _functions.insert(std::make_pair(S_CONTACT_INFO, &ProtocolServer::contactInfo));
//   _functions.insert(std::make_pair(S_CONTACT_REQUEST, &ProtocolServer::contactRequest));
//   _functions.insert(std::make_pair(S_CALL_REQUEST, &ProtocolServer::callRequest));
//   _functions.insert(std::make_pair(S_SEND_TEXT, &ProtocolServer::sendText));
//   _functions.insert(std::make_pair(S_HANGED_UP, &ProtocolServer::hangedUp));
//   _functions.insert(std::make_pair(S_SEND_FILE, &ProtocolServer::sendFile));
// }
//
// void ProtocolServer::methodChecker(DataToClient &toData)
// {
//   for (PointersOnFuncs::iterator it = _functions.begin(); it!=_functions.end(); ++it)
//     {
//       if ((*it)->first == toData.getType())
//         (*it)(server, toData);
//     }
// }
