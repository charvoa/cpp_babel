//
// RequestManager.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 26 11:07:14 2015 Nicolas Girardot
// Last update Mon Oct 26 20:14:14 2015 Nicolas Girardot
//

#ifndef DATAFROMCLIENT_HH_
# define DATAFROMCLIENT_HH_

# include <string>
# include <bitset>
# include <iostream>
# include <boost/algorithm/string/split.hpp>
# include <boost/algorithm/string.hpp>
# include <vector>

class DataFromClient
{
public:
  DataFromClient(const std::string &);
  ~DataFromClient();
  void DetermineType(const std::string &);
  void DetermineData(const std::string &);

private:
  //CommunicationType	_type;
  std::vector<std::string> _data;
};

#endif
