//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Tue Oct 27 10:05:05 2015 Antoine Garcia
//

#ifndef TCPProtocolHelper_HH_
# define TCPProtocolHelper_HH_

#include <string>
#include <cstdlib>
#include <QByteArray>
#include <QDataStream>
#include <map>
#include "IProtocolHelper.hh"

class	TCPProtocolHelper
{
  typedef QByteArray (TCPProtocolHelper::*funcPtr)();
  funcPtr	_ptr;
  typedef std::map<ProtocolType, funcPtr>	map_funcs;
  map_funcs	functions;
public:
  TCPProtocolHelper();
  ~TCPProtocolHelper();
  QByteArray  createRequest(ProtocolType type);
private:
  QByteArray	createHandshake();
};

#endif
