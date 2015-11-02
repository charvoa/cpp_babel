//
// Response.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:40:28 2015 Serge Heitzler
// Last update Mon Nov  2 14:47:30 2015 Serge Heitzler
//

#ifndef _RESPONSE_HH
# define _RESPONSE_HH

#include <string>
#include <vector>
#include "Account.hh"
#include "Common/TCPConnection.hh"
#include "CommunicationEnum.hh"

#define CHAR_SEPARATOR ";"

class		        Response
{
public:
  Response(CommunicationServer answerType, Account *toClient, std::vector<std::string> data);
  Response(CommunicationServer answerType, boost::shared_ptr<TCPConnection> toSocket, std::vector<std::string> data);
  ~Response();

  void           setSizeData(std::vector<std::string> data);
  void           setResponse(CommunicationServer answerType, std::vector<std::string> data);

  Account               *getClient();
  TCPConnection::pointer &getSocket();
  std::string           &getResponse();
  int extractBitsetValue(int startBit, int endBit, std::bitset<16> dataContainer);

private:

  Account               *_toClient;
  boost::shared_ptr<TCPConnection> *_toSocket;
  short                 _sizeData = 0;
  std::string           _response;
};

#endif /* !RESPONSE_HH_ */
