//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Sun Nov  1 15:48:41 2015 Nicolas Charvoz
//

#ifndef TCPProtocolHelper_HH_
# define TCPProtocolHelper_HH_

#include <QObject>
#include <string>
#include <cstdlib>
#include <QByteArray>
#include <QDataStream>
#include <map>
#include "IProtocolHelper.hh"

class	TCPProtocolHelper: public QObject
{
  Q_OBJECT
private:
  typedef QByteArray (TCPProtocolHelper::*funcPtr)();
  typedef void(TCPProtocolHelper::*handlePtr)();
  funcPtr	_ptr;
  handlePtr	_handlePtr;
  typedef std::map<ProtocolType, funcPtr>	map_funcs;
  typedef std::map<ProtocolType, handlePtr>	handle_funcs;
  map_funcs	functions;
  handle_funcs	handleFunctions;
  int _clientID;
public:
  TCPProtocolHelper();
  ~TCPProtocolHelper();
  QByteArray  createRequest(ProtocolType type);
  void	      handleRequest(qint8 type);
signals:
  void handshakeSuccess();
  //createRequest Method
private:
  QByteArray	createHandshake();
  QByteArray	createCallRequest();
  QByteArray	acceptCallRequest();
  //handleRequest Method
  void		handleHandshake();
};

#endif
