//
// main.cpp for  in /home/nicolaschr/rendu/test/babel/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Sep 20 20:19:52 2015 Nicolas Charvoz
// Last update Fri Oct  9 13:11:27 2015 Nicolas Charvoz
//

#include "../gui/MyApplication.hpp"
#include "../gui/MyWidget.hh"


int		main(int ac, char **av)
{
  MyApplication app(ac, av);
  MyWidget widget;

  QFile File("./gui/stylesheet.qss");
  File.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(File.readAll());

  app.setStyleSheet(StyleSheet);
  widget.show();

  return app.exec();
}
