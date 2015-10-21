//
// MyCurl.hpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:05:14 2015 Nicolas Charvoz
// Last update Wed Oct 21 12:20:51 2015 Antoine Garcia
//

#ifndef MYCURL_HH_
# define MYCURL_HH_

# include <iostream>
# include <string>
# include <QtNetwork>
# include <curl/curl.h>
# include "MainWidget.hh"

class MyCurl : QObject {

  Q_OBJECT
private:
  QObject *_parent;
public:
  MyCurl(QObject *parent = 0);
  ~MyCurl();
  int exec();


public slots:
  void slotReadyRead();
};

#endif
