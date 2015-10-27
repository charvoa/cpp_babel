//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Tue Oct 27 02:55:51 2015 Antoine Garcia
//

#ifndef TCPProtocolHelper_HH_
# define TCPProtocolHelper_HH_

#include <string>
#include <cstdlib>
#include "IProtocolHelper.hh"

class	TCPProtolHelper
{
  std::string	_data;
public:
  TCPProtolHelper(const std::string &data = NULL);
  ~TCPProtolHelper();
  void	writeHead(ProtocolType type);
  char		     readHeader(const std::string &);
  const std::string	&getData();
};

#endif
