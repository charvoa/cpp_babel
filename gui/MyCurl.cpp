//
// MyCurl.cpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:16:51 2015 Nicolas Charvoz
// Last update Tue Oct 27 11:26:25 2015 Nicolas Charvoz
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

void MyCurl::imgHandle()
{
  QNetworkAccessManager *nam = new QNetworkAccessManager(this);
  QUrl url(_code.c_str());
  qDebug() << url;
  QNetworkReply* reply = nam->get(QNetworkRequest(url));

  QEventLoop eventLoop;

  connect(reply,SIGNAL(finished()),&eventLoop,SLOT(quit()));
  eventLoop.exec();

  if (reply->error() == QNetworkReply::NoError)
    {
      QImageReader imageReader(reply);
      _img = imageReader.read();
    }
}

void MyCurl::dataHandle(const std::string &data)
{
  Document d;
  d.Parse(data.c_str());

  std::string tempString = d["query"]["results"]["channel"]
    ["item"]["condition"]["temp"].GetString();
  std::string condition = d["query"]["results"]["channel"]
    ["item"]["condition"]["text"].GetString();
  std::string codeString = d["query"]["results"]["channel"]
    ["item"]["condition"]["code"].GetString();
  int temp = this->getIntFromString(tempString);

  int code = this->getIntFromString(codeString);

  std::stringstream ss;
  ss << "http://l.yimg.com/a/i/us/we/52/" << code << ".gif";

  _code = ss.str();
  _tmp = (temp - 32) * 5.0 / 9;
  _condition = condition;

  this->imgHandle();
}

QImage &MyCurl::getImg()
{
  return _img;
}

int MyCurl::getTmp() const
{
  return _tmp;
}

std::string MyCurl::getCondition() const
{
  return _condition;
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
