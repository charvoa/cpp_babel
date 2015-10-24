//
// MyCurl.hpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:05:14 2015 Nicolas Charvoz
// Last update Sun Oct 25 00:54:54 2015 Nicolas Charvoz
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
  std::string getCondition() const;
  int getTmp() const;
  QImage &getImg();
  int exec();
  void dataHandle(const std::string &data);
  int getIntFromString(const std::string&);
  void imgHandle();
public slots:
  void slotReadyRead();

private:
  std::string _condition;
  int _tmp;
  std::string _code;
  QImage _img;
};

#endif
