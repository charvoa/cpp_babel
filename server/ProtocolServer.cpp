#include "ProtocolServer.hh"

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
  _functions[S_SUCCESS_HANDSHAKE] = &ProtocolServer::successHandshake;
  _functions[S_SUCCESS_ON_SIGN] = &ProtocolServer::successOnSign;
  _functions[S_ERROR_UNKNOWN] = &ProtocolServer::errorUnknown;
  _functions[S_ERROR_SIGN] = &ProtocolServer::errorSign;
  _functions[S_ERROR_CALL] = &ProtocolServer::errorCall;
  _functions[S_ERROR_NOT_IMPLEMENTED] = &ProtocolServer::errorNotImplemented;
  _functions[S_PING] = &ProtocolServer::ping;
  _functions[S_CONTACT_LIST] = &ProtocolServer::contactList;
  _functions[S_CONTACT_INFO] = &ProtocolServer::contactInfo;
  _functions[S_CONTACT_REQUEST] = &ProtocolServer::contactRequest;
  _functions[S_CALL_REQUEST] = &ProtocolServer::callRequest;
  _functions[S_SEND_TEXT] = &ProtocolServer::sendText;
  _functions[S_HANGED_UP] = &ProtocolServer::hangedUp;
  _functions[S_SEND_FILE] = &ProtocolServer::sendFile;
}

void ProtocolServer::methodChecker(Server &server, DataToClient &toData)
{
  for (PointersOnFuncs::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if (it->first == _functions[std::distance(_functions.begin(), it)].first)
        (*it)(server, toData);
    }
}
