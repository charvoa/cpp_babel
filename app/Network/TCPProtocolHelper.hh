//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Tue Oct 27 03:27:26 2015 Antoine Garcia
//

#ifndef TCPProtocolHelper_HH_
# define TCPProtocolHelper_HH_

#include <string>
#include <cstdlib>
#include <QByteArray>
#include <QDataStream>
#include "IProtocolHelper.hh"

class	TCPProtocolHelper
{
   typedef QByteArray& (TCPProtocolHelper::*funcPtr)();
  funcPtr	_funcs[2];
public:
  TCPProtocolHelper();
  ~TCPProtocolHelper();
  QByteArray  &createRequest(ProtocolType type);
private:
  QByteArray&	createHandshake();
};

#endif
