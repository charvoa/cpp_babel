//
// DataHandler.hpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:05:14 2015 Nicolas Charvoz
// Last update Wed Oct 28 14:37:59 2015 Nicolas Charvoz
//

#ifndef DATAHANDLER_HH_
# define DATAHANDLER_HH_

# include "MainWidget.hh"
# include "rapidjson/document.h"
# include "rapidjson/writer.h"
# include "rapidjson/stringbuffer.h"
# include <iostream>
# include <string>
# include <QtNetwork>
# include <sstream>

class DataHandler : public QObject {

  Q_OBJECT
private:
  QObject *_parent;
public:
  DataHandler(QObject *parent = 0);
  ~DataHandler();
  std::string getCondition() const;
  int getTmp() const;
  QImage &getImg();
  int exec();
  void dataHandle(const std::string &data);
  int getIntFromString(const std::string&);
  void imgHandle();
public slots:
  void slotReadyRead(QNetworkReply*);
signals:
  void canDisplayWeather();
private:
  std::string _condition;
  int _tmp;
  std::string _code;
  QImage _img;
  QNetworkAccessManager *_mgr;
};

#endif
