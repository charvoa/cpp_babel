//
// Response.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:16:36 2015 Serge Heitzler
// Last update Sun Nov  8 11:27:14 2015 Nicolas Girardot
//

#include <boost/lexical_cast.hpp>
#include "Response.hh"
#include "CommunicationEnum.hh"

Response::Response(CommunicationServer answerType, Account *toClient, std::vector<std::string> data)
{
  _toClient = toClient;
  this->setSizeData(data);
  this->setResponse(answerType, data);
}

Response::Response(CommunicationServer answerType, boost::shared_ptr<TCPConnection> toSocket, std::vector<std::string> data)
{
  _toSocket = toSocket;
  this->setSizeData(data);
  this->setResponse(answerType, data);
}

void           Response::setSizeData(std::vector<std::string> data)
{
  if (data.size() == 0)
    _sizeData = 0;
  else
    {
      for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
	{
	  _sizeData += (*it).length();
	  _sizeData++;
	}
      _sizeData--;
    }
  std::cout << "Data size is " << _sizeData << std::endl;
}

void           Response::setResponse(CommunicationServer answerType, std::vector<std::string> data)
{
  std::bitset<16> bit(_sizeData);
  _response += (char)(answerType);
  std::cout << "Setting response szie is " << data.size() << std::endl;
  _response += static_cast<char>(this->extractBitsetValue(0, 7, bit));
  std::cout << "Setting response" << std::endl;
  _response += static_cast<char>(this->extractBitsetValue(8, 15, bit));
  std::cout << "Setting response" << std::endl;
  if (_sizeData == 0)
    ;
  else
    {
      for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
	{
	  _response += (*it);
	  _response += CHAR_SEPARATOR;
	}
      _response.pop_back();
    }
  std::cout << "Olié Oliahhé" << std::endl;
}


Account           *Response::getClient()
{
  return _toClient;
}

boost::shared_ptr<TCPConnection>           Response::getSocket()
{
  return _toSocket;
}

std::string           &Response::getResponse()
{
  return _response;
}

int Response::extractBitsetValue(int startBit, int endBit, std::bitset<16> dataContainer)
{
  int maskLength = endBit - startBit + 1;
  int moveBitNr = startBit;
  std::bitset<16> mask;
  for(int k = 0; k < maskLength; k++)
    {
      mask.set(startBit + k, 1);
    }
  dataContainer.operator &=(mask);
  dataContainer.operator >>=(moveBitNr);
  std::cout << "It is working value is : " << dataContainer.to_ulong() << std::endl;
  return dataContainer.to_ulong();
}


Response::~Response()
{

}
