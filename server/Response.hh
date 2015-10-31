//
// Response.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:40:28 2015 Serge Heitzler
// Last update Sat Oct 31 16:40:32 2015 Serge Heitzler
//

#ifndef _RESPONSE_HH
# define _RESPONSE_HH

#include <string>
#include "ProtocolServer.hh"
#include "Account.hh"

#define CHAR_SEPARATOR ";"

class		        Response
{

  Response(ProtocolServer::CommunicationToClient answerType, std::vector<std::string> data);
  ~Response();

private:

  Account               *_toClient;
  short                 _sizeData = 0;
  std::string           _response;
};

#endif /* !RESPONSE_HH_ */
