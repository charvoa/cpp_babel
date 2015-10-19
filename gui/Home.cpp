//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sun Oct 18 14:05:22 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  QPixmap profilPicture("./gui/miranda2.jpg");
  QLabel *imgP = new QLabel(this);
  QLabel *currentName = new QLabel(this);

  imgP->setPixmap(profilPicture.scaled(120, 120, Qt::KeepAspectRatio));

  imgP->setGeometry(0, 0, 120, 120);
}
