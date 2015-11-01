//
// Response.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:16:36 2015 Serge Heitzler
// Last update Sun Nov  1 17:45:42 2015 Nicolas Girardot
//

#include <boost/lexical_cast.hpp>
#include "Response.hh"
#include "CommunicationEnum.hh"

Response::Response(CommunicationServer answerType, Account *toClient, std::vector<std::string> data)
{
  _toClient = toClient;
  //  this->setSizeData(data);
  this->setResponse(answerType, data);
}

Response::Response(CommunicationServer answerType, boost::shared_ptr<TCPConnection> toSocket, std::vector<std::string> data)
{
  _toSocket = &toSocket;
  this->setSizeData(data);
  this->setResponse(answerType, data);
}

void           Response::setSizeData(std::vector<std::string> data)
{
  std::cout << "Cotsa" << std::endl;
  for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
      _sizeData += (*it).length();
      _sizeData++;
      std::cout << "COtssaa" << std::endl;
    }
  _sizeData--;
}

void           Response::setResponse(CommunicationServer answerType, std::vector<std::string> data)
{
  std::bitset<16> bit(_sizeData);


  _response += boost::lexical_cast<char>(answerType);
  /* diviser la taille en deux octets

  _response.push_back(firstBit);
  _response.push_back(secondBit);

  */

  for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
      _response += (*it);
      _response += CHAR_SEPARATOR;
    }
    _response.pop_back();
}


Account           *Response::getClient()
{
  return _toClient;
}

boost::shared_ptr<TCPConnection>           &Response::getSocket()
{
  return *_toSocket;
}

std::string           &Response::getResponse()
{
  return _response;
}

Response::~Response()
{

}
