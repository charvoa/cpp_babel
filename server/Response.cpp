//
// Response.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:16:36 2015 Serge Heitzler
// Last update Mon Nov  2 11:21:43 2015 Serge Heitzler
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
  if (data.size() == 0)
    _sizeData = 0;
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
  _response += boost::lexical_cast<char>(this->extractBitsetValue(0, 7, bit));
  _response += boost::lexical_cast<char>(this->extractBitsetValue(8, 15, bit));
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
	return dataContainer.to_ulong();
}


Response::~Response()
{

}
