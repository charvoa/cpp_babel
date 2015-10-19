//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Mon Oct 19 13:43:21 2015 Antoine Garcia
//

#ifndef TCPProtolHelper_HH_
# define TCPProtolHelper_HH_

#include <string>

typedef enum TCPProtocolHeader
  {
    SIGNIN,
    SIGNUP
  }TCPProtolHeader;

class	TCPProtolHelper
{
public:
  TCPProtolHelper();
  ~TCPProtolHelper();
  const std::string &writeHead(TCPProtolHelper type);
};

#endif
