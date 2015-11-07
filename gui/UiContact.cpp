//
// UiContact.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sat Nov  7 15:25:58 2015 Nicolas Charvoz
//

#include "UiContact.hh"

UiContact::UiContact(MainWidget *main, QWidget *parent) : QWidget(parent),
							  _main(main)
{
  this->displayContact();
  connect(&g_PTUser, SIGNAL(contactAdded()), this, SLOT(refreshUI()));
}

void UiContact::displayContact()
{
  QLabel *imgP;
  QLabel *name;
  QPushButton *newConv;
  QPixmap *profilPic;

  std::stringstream ss;
  int j = 0;
  int i = 0;

  for (int tmp = 0; tmp < 15; tmp++)
    {
      if (i % 7 == 0 && i != 0)
	{
	  i = 0;
	  j++;
	}
      ss << "Username " << tmp;

      name = new QLabel(tr(ss.str().c_str()), this);
      name->setAlignment(Qt::AlignCenter);

      name->setGeometry((30 * (i + 1) + 240 * i), (30 + 390 * j),
			240, 60);
      profilPic = new QPixmap("./gui/img/avatar1.png");
      imgP = new QLabel(this);
      imgP->setPixmap(profilPic->scaled(240, 240));
      imgP->setGeometry((30 * (i + 1) + 240 * i), (90 + 390 * j),
			240, 240);
      newConv = new QPushButton(tr(ss.str().c_str()), this);
      newConv->setGeometry((30 * (i + 1) + 240 * i), (330 + 390 * j),
			   240, 60);
      newConv->setObjectName(ss.str().c_str());
      newConv->setFocusPolicy(Qt::NoFocus);
      connect(newConv, SIGNAL(released()), this, SLOT(addTab()));

      ss.str("");
      ss.clear();
      i++;
    }
  setMinimumSize(270*7,420*(15/7+1));
}

void UiContact::refreshUI()
{
  QLabel *imgP;
  QLabel *name;
  QPushButton *newConv;
  QPixmap *profilPic;

  std::stringstream ss;
  int j = 0;
  int i = 0;

  for (int tmp = 0; tmp < 16; tmp++)
    {
      if (i % 7 == 0 && i != 0)
	{
	  i = 0;
	  j++;
	}
      ss << "Username " << tmp;

      name = new QLabel(tr(ss.str().c_str()), this);
      name->setAlignment(Qt::AlignCenter);

      name->setGeometry((30 * (i + 1) + 240 * i), (30 + 390 * j),
			240, 60);
      profilPic = new QPixmap("./gui/img/avatar1.png");
      imgP = new QLabel(this);
      imgP->setPixmap(profilPic->scaled(240, 240));
      imgP->setGeometry((30 * (i + 1) + 240 * i), (90 + 390 * j),
			240, 240);
      newConv = new QPushButton(tr(ss.str().c_str()), this);
      newConv->setGeometry((30 * (i + 1) + 240 * i), (330 + 390 * j),
			   240, 60);
      newConv->setObjectName(ss.str().c_str());
      newConv->setFocusPolicy(Qt::NoFocus);
      connect(newConv, SIGNAL(released()), this, SLOT(addTab()));
      ss.str("");
      ss.clear();
      i++;
    }
}

void UiContact::addTab()
{
  //  QPushButton *b = dynamic_cast<QPushButton*>(sender());
  std::cout << sender()->objectName().toUtf8().constData() << std::endl;
  if (sender() != NULL)
    {
      if (!(g_PTUser.isTabOpen(sender()->objectName().toUtf8().constData())))
	{
	  _main->addTab(sender()->objectName().toUtf8().constData());
	  g_PTUser.addToList(sender()->objectName().toUtf8().constData());
	}
    }
}
