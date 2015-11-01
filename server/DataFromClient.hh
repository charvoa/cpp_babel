//
// RequestManager.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:07:14 2015 Nicolas Girardot
// Last update Sun Nov  1 11:59:04 2015 Nicolas Girardot
//

#ifndef DATAFROMCLIENT_HH
# define DATAFROMCLIENT_HH

# include <string>
# include <bitset>
# include <iostream>
# include <boost/algorithm/string/split.hpp>
# include <boost/algorithm/string.hpp>
# include <vector>
# include "CommunicationEnum.hh"
# include "ProtocolClient.hh"

class ProtocolClient;

class DataFromClient
{
public:
  DataFromClient(const std::string &);
  ~DataFromClient();
  void DetermineType(const std::string &);
  void DetermineData(const std::string &);
  void	DetermineClientID(const std::string &);
  std::vector<std::string> &getData();
  CommunicationClient	getType();
  std::string &getClientID();


private:
  std::vector<std::string> _data;
  std::string              _clientID;
  CommunicationClient _type;
};

#endif
