//
// Response.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:16:36 2015 Serge Heitzler
// Last update Sat Oct 31 16:46:02 2015 Serge Heitzler
//

#include "Response.hh"

Response::Response(ProtocolServer::CommunicationToClient answerType, std::vector<std::string> data)
{
  this.setSizeData(data);
  this.setResponse(answerType, data);
}

void           Response::setSizeData(std::vector<std::string> data)
{
  for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
      _sizeData += (*it)->length();
      _sizeData++;
    }
  _sizeData--;
}

void           Response::setResponse(ProtocolServer::CommunicationToClient answerType, std::vector<std::string> data)
{
  std::bitset<16> bit(_sizeData);


  _response.append<int>(answerType);
  /* diviser la taille en deux octets

  _response.append(firstBit);
  _response.append(secondBit);

  */

  for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
      _response.append((*it));
      _response.append(CHAR_SEPARATOR);
    }
    _response.pop_back();
}

Response::~Response()
{

}
