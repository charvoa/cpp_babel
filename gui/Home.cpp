//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Mon Oct 19 19:34:35 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  QPixmap profilPicture("./gui/miranda2.jpg");
  QLabel *imgP = new QLabel(this);
  QLabel *currentName = new QLabel(this);
  QFont f("Calibri", 18, QFont::Bold);

  imgP->setPixmap(profilPicture.scaled(120, 120, Qt::KeepAspectRatio));

  currentName->setText(tr("Miranda Kerr"));
  imgP->setGeometry(0, 0, 120, 120);
  currentName->setFont(f);
  currentName->setGeometry(130, 0, 300, 60);
}
