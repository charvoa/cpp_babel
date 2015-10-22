//
// MyCurl.cpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:16:51 2015 Nicolas Charvoz
// Last update Wed Oct 21 23:18:12 2015 Nicolas Charvoz
//

#include "MyCurl.hh"

using namespace rapidjson;

MyCurl::MyCurl(QObject *parent) : _parent(parent)
{
}

MyCurl::~MyCurl() {}

int MyCurl::getIntFromString(const std::string &str)
{
  int asint = 0;
  std::stringstream ss;

  ss << str;
  ss >> asint;
  ss.str("");
  ss.clear();

  return asint;
}

void MyCurl::dataHandle(const std::string &data)
{
  //  std::cout << data << std::endl;

  Document d;

  d.Parse(data.c_str());

  std::string tempString = d["query"]["results"]["channel"]
    ["item"]["condition"]["temp"].GetString();

  std::string condition = d["query"]["results"]["channel"]
    ["item"]["condition"]["text"].GetString();

  int temp = this->getIntFromString(tempString);

  int tempC = (temp - 32) * 5.0 / 9;

  std::cout << "It's " << condition << ". The outside temparature is "
	    << tempC << std::endl;
}

int MyCurl::exec()
{
  const char *query = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20614274&format=json";

  QEventLoop eventLoop;

  // "quit()" the event-loop, when the network request "finished()"
  QNetworkAccessManager mgr;
  QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

  // the HTTP request
  QNetworkRequest req(QUrl(tr(query)));
  QNetworkReply *reply = mgr.get(req);

  eventLoop.exec(); // blocks stack until "finished()" has been called

  if (reply->error() == QNetworkReply::NoError)
    {
      //success
      //      qDebug() << "Success" << reply->readAll();
      QString content = reply->readAll();
      this->dataHandle(content.toUtf8().constData());
      delete reply;
    }
  else
    {
      //failure
      qDebug() << "Failure" << reply->errorString();
      delete reply;
    }

  return 0;
}


void MyCurl::slotReadyRead()
{

}
