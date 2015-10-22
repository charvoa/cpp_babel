#include "ProtocolServer.hh"

bool	ProtocolServer::ping(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::contactList(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::contactInfo(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::contactRequest(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::callRequest(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::sendText(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::hangedUp(Server &server, DataToClient &data)
{

}

bool	ProtocolServer::sendFile(Server &server, DataToClient &data)
{

}

void ProtocolServer::initMethod()
{
  _functions[] = &ProtocolServer::ping;
  _functions[] = &ProtocolServer::contactList;
  _functions[] = &ProtocolServer::contactInfo;
  _functions[] = &ProtocolServer::contactRequest;
  _functions[] = &ProtocolServer::callRequest;
  _functions[] = &ProtocolServer::sendText;
  _functions[] = &ProtocolServer::hangedUp;
  _functions[] = &ProtocolServer::sendFile;
  /* faire de même pour chaque fonctions */
}

void ProtocolServer::methodChecker(Server &server, AData &DataToClient)
{
  // std::string cmd(command, 0, 3);
  // for (std::map<std::string, funcs>::iterator it = _functions.begin(); it!=_functions.end(); ++it)
  //   {
  //     if (it->first == cmd)
	// (*this.*_functions[cmd])(command, game);
  //   }
}
