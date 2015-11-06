//
// NetworkHandler.hh for NetworkHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 14 06:40:54 2015 Antoine Garcia
// Last update Fri Nov  6 13:22:47 2015 Antoine Garcia
//

#ifndef NETWORKHANDLER_HH_
# define NETWORKHANDLER_HH_

#include <QObject>
#include <QString>
#include <QAbstractSocket>
#include "INetwork.hh"
#include "TCPProtocolHelper.hh"

class QTcpSocket;
class NetworkServerHandler : public QObject, public INetwork
{
  Q_OBJECT
private:
  QObject *parent;
  QTcpSocket *_socket;
  std::string _host;
  unsigned int _port;
  bool		_connected;
  TCPProtocolHelper	_request;
  QByteArray		_read;
signals:
  void	userConnected(int check);
public:
  int			type;
  std::string		login;
  std::string		password;
  NetworkServerHandler(QObject *parent = 0);
  ~NetworkServerHandler();
  int start(const std::string &host, unsigned int port);
  void setHost(const std::string &);
  void setPort(unsigned int);
  void write(const std::string &);
  void	handShake();
  bool getConnectionStatus() const;
  void	logUser();
  void	signUser();
private slots:
  void	readyRead();
  void	connected();
  void	connectionError(QAbstractSocket::SocketError);
  void	handshakeSuccess();
  void	loginSuccess();
  void	loginError();
  void	addContactSuccess();
};

#endif
