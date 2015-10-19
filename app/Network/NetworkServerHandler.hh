//
// NetworkHandler.hh for NetworkHandler in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 14 06:40:54 2015 Antoine Garcia
// Last update Mon Oct 19 12:41:37 2015 Antoine Garcia
//

#ifndef NETWORKHANDLER_HH_
# define NETWORKHANDLER_HH_

#include <QObject>
#include <QString>
#include "INetwork.hh"

class QTcpSocket;

class NetworkServerHandler : public QObject, public INetwork
{
  Q_OBJECT
private:
  QObject *parent;
  QTcpSocket *_socket;
  std::string _host;
  unsigned int _port;
public:
  NetworkServerHandler(QObject *parent = 0);
  ~NetworkServerHandler();
  int start(const std::string &host, unsigned int port);
  void setHost(const std::string &);
  void setPort(unsigned int);
  void write(const std::string &);
private slots:
  void	readyRead();
  void	connected();
};

#endif
