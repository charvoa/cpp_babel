//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Sun Nov  8 08:32:51 2015 Antoine Garcia
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

typedef enum handlerProtocol
  {
    HANDSHAKESUCCESS = 101,
    SUCCESSLOGIN = 102,
    ERRORLOGIN = 106,
    ADDCONTACTSUCCESS = 111,
    CALLING = 112
  }	    protocolClient;

class	TCPProtocolHelper: public QObject
{
  Q_OBJECT
private:
  typedef QByteArray (TCPProtocolHelper::*funcPtr)();
  typedef void(TCPProtocolHelper::*handlePtr)();
  funcPtr	_ptr;
  handlePtr	_handlePtr;
  typedef std::map<ProtocolType, funcPtr>	map_funcs;
  typedef std::map<protocolClient, handlePtr>	handle_funcs;
  map_funcs	functions;
  handle_funcs	handleFunctions;
  QByteArray	 _clientID;

public:
  TCPProtocolHelper();
  ~TCPProtocolHelper();
  QByteArray  createRequest(ProtocolType type);
  void	      handleRequest(qint8 type);
  void	      parseLoginSuccess(QByteArray &array);
  const QByteArray &getClientID() const {
    return _clientID;
  };
signals:
  void handshakeSuccess();
  void	loginSuccess();
  void	loginError();
  void	addContactSuccess();
  //createRequest Method
private:
  QByteArray	createHandshake();
  QByteArray	createCallRequest();
  QByteArray	acceptCallRequest();
  QByteArray	addContactRequest();
  //handleRequest Method
  void		handleHandshake();
  void		handleLogin();
  void		errorLogin();
  void		handleContactSuccess();
  void		handleCall();
};

#endif
