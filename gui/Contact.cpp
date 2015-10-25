//
// Contact.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sun Oct 25 12:46:35 2015 Nicolas Charvoz
//

#include "Contact.hh"

Contact::Contact(MainWidget *main, QWidget *parent) : QWidget(parent), _main(main)
{
  //  QLabel *fileNameLabel = new QLabel(tr("Contact"));

  /* */
  this->displayContact();
}

void Contact::displayContact()
{
  QLabel *imgP;
  QLabel *name;
  QPushButton *newConv;
  QPixmap *profilPic;

  std::stringstream ss;
  int j = 0;
  int i = 0;
  QScrollArea *scrollArea = new QScrollArea(this);

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
      newConv = new QPushButton(tr("Chat"), this);
      newConv->setGeometry((30 * (i + 1) + 240 * i), (330 + 390 * j),
			   240, 60);
      newConv->setFocusPolicy(Qt::NoFocus);
      connect(newConv, SIGNAL(released()), this, SLOT(addTab()));

      ss.str("");
      ss.clear();
      i++;
    }
}

void Contact::addTab()
{
  _main->addTab("new");
}
