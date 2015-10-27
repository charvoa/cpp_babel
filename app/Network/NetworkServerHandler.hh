//
// NetworkHandler.hh for NetworkHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 14 06:40:54 2015 Antoine Garcia
// Last update Tue Oct 27 03:11:20 2015 Antoine Garcia
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
signals:
  void	userConnected(int check);
public:
  NetworkServerHandler(QObject *parent = 0);
  ~NetworkServerHandler();
  int start(const std::string &host, unsigned int port);
  void setHost(const std::string &);
  void setPort(unsigned int);
  void write(const std::string &);
  void	handShake();
  void	logUser();
  bool getConnectionStatus() const;
private slots:
  void	readyRead();
  void	connected();
  void	connectionError(QAbstractSocket::SocketError);
};

#endif
