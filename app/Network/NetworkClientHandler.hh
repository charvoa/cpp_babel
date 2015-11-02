//
// NetworkClientHandler.hh for cpp_babel in /home/louis/rendu/cpp_babel/app/Network
//
// Made by Louis Audibert
// Login   <louis@epitech.net>
//
// Started on  Sun Nov  1 04:52:13 2015 Louis Audibert
// Last update Sun Nov  1 17:56:48 2015 Louis Audibert
//

#ifndef NETWORKCLIENTHANDLER_HH_
# define NETWORKCLIENTHANDLER_HH_

#include <QObject>
#include <QString>
#include <QAbstractSocket>
#include "INetwork.hh"
#include "TCPProtocolHelper.hh"

class QUdpSocket;
class NetworkClientHandler : public QObject, public INetwork
{
  Q_OBJECT
private:
  QObject		*parent;
  QUdpSocket		*_socket;
  std::string		_host;
  unsigned int		_port;
  bool			_connected;
  TCPProtocolHelper	_request;

public:
  NetworkClientHandler(QObject *parent = 0);
  ~NetworkClientHandler();

  void			testUDP(std::string &);
  int			start(const std::string &host, unsigned int port);
  void			setHost(const std::string &);
  void			setPort(unsigned int);
  void			write(const std::string &);

public slots:
  void			readyRead();
};

#endif
