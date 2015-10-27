//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Tue Oct 27 17:45:17 2015 Nicolas Charvoz
//

#include "Home.hh"
#include <QApplication>

Home::Home(QWidget *parent) : QWidget(parent)
{
  /* MODIFY THIS PICTURE */
  QPixmap profilPicture("./gui/img/miranda2.jpg");
  QLabel *imgP = new QLabel(this);
  QLabel *currentName = new QLabel(this);
  QFont f("Calibri", 18, QFont::Bold);
  QPushButton *add = new QPushButton(("Add Friend"), this);
  _addFriend = new QLineEdit(this);

  imgP->setPixmap(profilPicture.scaled(120, 120, Qt::KeepAspectRatio));

  /* MODIFY THIS TEXT */
  currentName->setText(tr("Miranda Kerr"));
  imgP->setGeometry(0, 0, 120, 120);
  currentName->setFont(f);
  currentName->setGeometry(130, 0, 300, 60);
  _addFriend->setGeometry(835, 480, 250, 60);
  add->setGeometry(835, 540, 250, 60);

  _imgWeather = new QLabel(this);
  _temp = new QLabel(this);

  _imgWeather->setGeometry(1700, 0, 120, 120);
  _temp->setGeometry(1710, 100, 60, 60);

  this->weatherDisplay();
}

void Home::canDisplayWeather()
{
  _str = std::to_string(_mC->getTmp());

  char const *pchar = _str.c_str();

  _temp->setText(tr(pchar));

  _imgWeather->setPixmap(QPixmap::fromImage(_mC->getImg()));
}

int Home::weatherDisplay()
{
  _mC = new MyCurl();

  _mC->exec();
  connect(_mC, SIGNAL(canDisplayWeather()), this, SLOT(canDisplayWeather()));

  return 0;
}

void Home::validateFriend(int error)
{
  (void) error;
}

void Home::addFriend()
{
  QString friendToAdd = _addFriend->text();
  std::string _friendString = friendToAdd.toUtf8().constData();

  _addFriend->clear();

    // g_PTUser.addFriend();
}
