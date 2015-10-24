//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sun Oct 25 00:58:37 2015 Nicolas Charvoz
//

#include "Home.hh"

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

  this->weatherDisplay();
}

int Home::weatherDisplay()
{
  MyCurl *mC = new MyCurl();

  std::cout << "weather " << std::endl;
  mC->exec();

  std::cout << "Condition : " << mC->getCondition()
	    << " Tmp °C : " << mC->getTmp() << std::endl;

  std::string s = std::to_string(mC->getTmp());
  char const *pchar = s.c_str();

  QLabel *temp = new QLabel(tr(pchar), this);

  QLabel *imgWeather = new QLabel(this);

  imgWeather->setPixmap(QPixmap::fromImage(mC->getImg()));

  imgWeather->setGeometry(1700, 0, 120, 120);
  temp->setGeometry(1710, 130, 60, 60);
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
