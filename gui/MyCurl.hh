//
// MyCurl.hpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:05:14 2015 Nicolas Charvoz
// Last update Wed Oct 21 23:14:59 2015 Nicolas Charvoz
//

#ifndef MYCURL_HH_
# define MYCURL_HH_

# include "MainWidget.hh"
# include "rapidjson/document.h"
# include "rapidjson/writer.h"
# include "rapidjson/stringbuffer.h"
# include <iostream>
# include <string>
# include <QtNetwork>
# include <sstream>

class MyCurl : QObject {

  Q_OBJECT
private:
  QObject *_parent;
public:
  MyCurl(QObject *parent = 0);
  ~MyCurl();
  int exec();
  void dataHandle(const std::string &data);
  int getIntFromString(const std::string&);
public slots:
  void slotReadyRead();
};

#endif