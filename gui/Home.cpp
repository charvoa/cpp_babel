//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Wed Oct 21 14:51:16 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  QPixmap profilPicture("./gui/img/miranda2.jpg");
  QLabel *imgP = new QLabel(this);
  QLabel *currentName = new QLabel(this);
  QFont f("Calibri", 18, QFont::Bold);
  QPushButton *add = new QPushButton(("Add Friend"), this);
  _addFriend = new QLineEdit(this);

  imgP->setPixmap(profilPicture.scaled(120, 120, Qt::KeepAspectRatio));

  currentName->setText(tr("Miranda Kerr"));
  imgP->setGeometry(0, 0, 120, 120);
  currentName->setFont(f);
  currentName->setGeometry(130, 0, 300, 60);
  _addFriend->setGeometry(835, 480, 250, 60);
  add->setGeometry(835, 540, 250, 60);
}

void validateFriend(int error)
{
}

void Home::addFriend()
{
  QString friendToAdd = _addFriend->text();
  std::string _friendString = friendToAdd.toUtf8().constData();

  _addFriend->clear();

    // g_PTUser.addFriend();
}
