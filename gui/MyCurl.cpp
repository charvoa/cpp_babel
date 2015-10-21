//
// MyCurl.cpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:16:51 2015 Nicolas Charvoz
// Last update Wed Oct 21 18:36:22 2015 Nicolas Charvoz
//

#include "MyCurl.hh"

MyCurl::MyCurl(QObject *parent) : _parent(parent)
{
}

MyCurl::~MyCurl() {}

int MyCurl::exec()
{
  QNetworkAccessManager *manager = new QNetworkAccessManager();
  QNetworkRequest request;

  request.setUrl(QUrl("www.nicolascharvoz.com/"));

  QNetworkReply *reply = manager->get(request);

  connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
  connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
	  this, SLOT(slotError(QNetworkReply::NetworkError)));
  connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
	  this, SLOT(slotSslErrors(QList<QSslError>)));

  return 0;
}


void MyCurl::slotReadyRead()
{

}
