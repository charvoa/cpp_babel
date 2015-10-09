//
// main.cpp for  in /home/nicolaschr/rendu/test/babel/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Sep 20 20:19:52 2015 Nicolas Charvoz
// Last update Fri Oct  9 14:36:56 2015 Nicolas Charvoz
//

#include "../gui/MyApplication.hpp"
#include "../gui/MyWidget.hh"
#include "../gui/LoginWidget.hh"


int		main(int ac, char **av)
{
  MyApplication app(ac, av);
  LoginWidget *login;

  login = new LoginWidget;

  /* Opening CSS file */
  QFile File("./gui/stylesheet.qss");
  File.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(File.readAll());

  /* Applying it */
  app.setStyleSheet(StyleSheet);

  /* Show login window */
  login->setAttribute(Qt::WA_DeleteOnClose);
  login->show();

  return app.exec();
}
