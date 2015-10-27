//
// RequestManager.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:07:17 2015 Nicolas Girardot
// Last update Mon Oct 26 20:14:54 2015 Nicolas Girardot
//

#include "DataFromClient.hh"

DataFromClient::DataFromClient(const std::string &request)
{
  std::cout << "Request Manager Constructor Beginning" << std::endl;
  DetermineType(request);
  DetermineData(request);
  std::cout << "Request Manager Constructor End" << std::endl;
}

DataFromClient::~DataFromClient() {}

void	DataFromClient::DetermineType(const std::string &request)
{
  std::bitset<8> b_type(request.at(0));
  long	l_type = b_type.to_ulong();
  //  _type = static_cast<CommunicationType>(l_type);
  std::cout << "Displaying l_type in DataFromClient.cpp : " << l_type << std::endl;
  std::cout << "DataFromClient::DetermineType end" << std::endl;
}

void	DataFromClient::DetermineData(const std::string &request)
{
  std::string copy(request);
  copy.erase(0,3);
  boost::split(_data, copy, boost::is_any_of(";"));
  for (std::vector<std::string>::iterator pos = _data.begin(); pos != _data.end(); ++pos)
    {
      std::cout << "Argument from data = " << *pos << std::endl;
    }
}
