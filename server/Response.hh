//
// Response.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:40:28 2015 Serge Heitzler
// Last update Sun Nov  1 15:50:05 2015 Serge Heitzler
//

#ifndef _RESPONSE_HH
# define _RESPONSE_HH

#include <string>
#include "ProtocolServer.hh"
#include "Account.hh"
#include "Common/TCPConnection.hh"

#define CHAR_SEPARATOR ";"

class		        Response
{

public:
  Response(CommunicationServer answerType, Account *toClient, std::vector<std::string> data);
  Response(CommunicationServer answerType, boost::shared_ptr<TCPConnection> toSocket, std::vector<std::string> data);
  ~Response();

  void           setSizeData(std::vector<std::string> data);
  void           setResponse(CommunicationServer answerType, std::vector<std::string> data);

private:

  Account               &_toClient;
  boost::shared_ptr<TCPConnection> _toSocket;
  short                 _sizeData = 0;
  std::string           _response;
};

#endif /* !RESPONSE_HH_ */
