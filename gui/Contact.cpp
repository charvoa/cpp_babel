//
// Contact.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Wed Oct 21 14:51:43 2015 Nicolas Charvoz
//

#include "Contact.hh"

Contact::Contact(MainWidget *main, QWidget *parent) : QWidget(parent), _main(main)
{
  //  QLabel *fileNameLabel = new QLabel(tr("Contact"));
  QVBoxLayout *mainLayout = new QVBoxLayout;


  /* */
  this->displayContact();
}

void Contact::displayContact()
{
  QPixmap profilPic("./gui/img/miranda2.jpg");
  QLabel *imgP = new QLabel(this);
  QPushButton *newConv = new QPushButton(tr("Chat"),
					    this);
  QLabel *name = new QLabel(tr("Mirand Kerr"), this);

  name->setGeometry(30, 10, 120, 60);
  imgP->setPixmap(profilPic.scaled(120, 120));
  imgP->setGeometry(30, 70, 120, 120);
  newConv->setGeometry(30, 190, 120, 60);
  newConv->setFocusPolicy(Qt::NoFocus);
  connect(newConv, SIGNAL(released()), this, SLOT(addTab()));
}

void Contact::addTab()
{
  _main->addTab("new");
}
