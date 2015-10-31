#include "Response.hh"

Response::Response(AProtocol::CommunicationType answerType, std::vector<std::string> data)
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

void           Response::setResponse(AProtocol::CommunicationType answerType, std::vector<std::string> data)
{
  std::bitset<16> bit(_sizeData);

  _response.append<int>(answerType);
  _response.append(bit);
  
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
