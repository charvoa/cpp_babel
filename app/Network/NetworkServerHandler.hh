//
// NetworkHandler.hh for NetworkHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 14 06:40:54 2015 Antoine Garcia
<<<<<<< HEAD
// Last update Wed Oct 21 05:35:04 2015 Antoine Garcia
=======
// Last update Tue Oct 20 16:20:15 2015 Nicolas Charvoz
>>>>>>> b4b391075d3452ade76d806abc896820b302fd60
//

#ifndef NETWORKHANDLER_HH_
# define NETWORKHANDLER_HH_

#include <QObject>
#include <QString>
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
public:
  NetworkServerHandler(QObject *parent = 0);
  ~NetworkServerHandler();
  int start(const std::string &host, unsigned int port);
  void setHost(const std::string &);
  void setPort(unsigned int);
  void write(const std::string &);
  void	handShake();
  bool getConnectionStatus();
private slots:
  void	readyRead();
  void	connected();
};

#endif
