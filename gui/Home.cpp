//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sun Oct 18 12:18:44 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  QPixmap profilPicture("./gui/miranda2.jpg");
  QLabel *imgP = new QLabel(this);

  imgP->setPixmap(profilPicture);

  imgP->setGeometry(0, 0, 60, 60);
}
