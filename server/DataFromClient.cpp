//
// RequestManager.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:07:14 2015 Nicolas Girardot
// Last update Sun Nov  1 15:08:15 2015 Nicolas Girardot
//

#	include "DataFromClient.hh"

DataFromClient::DataFromClient(const std::string &request)
{
  std::cout << "Request Manager Constructor Beginning" << std::endl;
  DetermineType(request);
  DetermineClientID(request);
  DetermineData(request);
  std::cout << "Request Manager Constructor End" << std::endl;
  ProtocolClient *proto = new ProtocolClient;
  proto->methodChecker(*this);
}

DataFromClient::~DataFromClient() {}

void	DataFromClient::DetermineType(const std::string &request)
{
  std::bitset<8> b_type(request.at(0));
  long	l_type = b_type.to_ulong();
  _type = static_cast<CommunicationClient>(l_type);
  std::cout << "Displaying l_type in DataFromClient.cpp : " << l_type << std::endl;
  std::cout << "DataFromClient::DetermineType end" << std::endl;
}

CommunicationClient	DataFromClient::getType()
{
  return _type;
}

std::vector<std::string> &DataFromClient::getData()
{
  return (_data);
}

std::string &DataFromClient::getClientID()
{
  return _clientID;
}

void	DataFromClient::DetermineClientID(const std::string &request)
{
  std::bitset<8> a(request.at(1));
  std::bitset<8> b(request.at(2));
  std::bitset<8> c(request.at(3));
  std::bitset<8> d(request.at(4));

  unsigned long i = a.to_ulong();
  unsigned char j = static_cast<unsigned char>(i);
  _clientID += j;
  i = b.to_ulong();
  j = static_cast<unsigned char>(i);
  _clientID += j;
  i = c.to_ulong();
  j = static_cast<unsigned char>(i);
  _clientID += j;
  i = d.to_ulong();
  j = static_cast<unsigned char>(i);
  _clientID += j;
}

void	DataFromClient::DetermineData(const std::string &request)
{
  std::string copy(request);
  copy.erase(0,7);
  boost::split(_data, copy, boost::is_any_of(";"));
}
