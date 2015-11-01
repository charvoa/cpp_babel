//
// Response.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:16:36 2015 Serge Heitzler
// Last update Sun Nov  1 12:26:29 2015 Serge Heitzler
//

#include "Response.hh"
#include "CommunicationEnum.hh"

Response::Response(CommunicationServer answerType, Account *toClient, std::vector<std::string> data)
{
  _toClient = toClient;
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

void           Response::setResponse(CommunicationServer answerType, std::vector<std::string> data)
{
  std::bitset<16> bit(_sizeData);


  _response.push_back(std::to_string(boost::lexical_cast<char>(answerType));
  /* diviser la taille en deux octets

  _response.push_back(firstBit);
  _response.push_back(secondBit);

  */

  for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
      _response.push_back((*it));
      _response.push_back(CHAR_SEPARATOR);
    }
    _response.pop_back();
}

Response::~Response()
{

}
