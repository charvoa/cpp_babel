//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sat Nov  7 16:15:50 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  /* MODIFY THIS PICTURE */
  QPixmap profilPicture("./gui/img/avatar1.png");
  QLabel *imgP = new QLabel(this);
  QLabel *currentName = new QLabel(this);
  QFont f("Calibri", 18, QFont::Bold);
  QPushButton *add = new QPushButton(("Add Friend"), this);
  _addFriend = new QLineEdit(this);

  imgP->setPixmap(profilPicture.scaled(120, 120, Qt::KeepAspectRatio));

  /* MODIFY THIS TEXT */
  std::string userName = g_PTUser.currentUser().getUsername();
  std::cout << "Username : " << userName << std::endl;
  currentName->setText(tr(userName.c_str()));
  imgP->setGeometry(0, 0, 120, 120);
  currentName->setFont(f);
  currentName->setGeometry(130, 0, 300, 60);
  _addFriend->setGeometry(835, 480, 250, 60);
  add->setGeometry(835, 540, 250, 60);

  _imgWeather = new QLabel(this);
  _temp = new QLabel(this);

  _imgWeather->setGeometry(1700, 0, 120, 120);
  _temp->setGeometry(1710, 100, 60, 60);

  connect(add, SIGNAL(released()), this, SLOT(addFriend()));
  connect(&g_PTUser, SIGNAL(contactAdded()), this, SLOT(contactAdded()));

  this->weatherDisplay();
}

void Home::canDisplayWeather()
{
  _str = std::to_string(_dH->getTmp());

  char const *pchar = _str.c_str();

  _temp->setText(tr(pchar) + "°C");

  _imgWeather->setPixmap(QPixmap::fromImage(_dH->getImg()));
}

int Home::weatherDisplay()
{
  _dH = new DataHandler();

  _dH->exec();
  connect(_dH, SIGNAL(canDisplayWeather()), this, SLOT(canDisplayWeather()));

  return 0;
}

void Home::contactAdded()
{
  QMessageBox msgBox;

  msgBox.setText("Yeah ! You added a friend !");
  msgBox.exec();
  std::cout << "contact added" << std::endl;
}

void Home::addFriend()
{
  QString friendToAdd = _addFriend->text();
  std::string _friendString = friendToAdd.toUtf8().constData();

  if (_friendString != "")
    {
      _addFriend->clear();
      g_PTUser.currentUser().addContact();
    }
  else
    {
      QMessageBox msgBox;

      msgBox.setText("Oh oh, you must write a valid name in the box !");
      msgBox.exec();
    }
}
