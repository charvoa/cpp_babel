//
// Contact.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Mon Oct 12 12:31:34 2015 Nicolas Charvoz
//

#include "Contact.hh"

Contact::Contact(MainWidget *main, QWidget *parent) : QWidget(parent), _main(main)
{
  QLabel *fileNameLabel = new QLabel(tr("Contact"));
  QVBoxLayout *mainLayout = new QVBoxLayout;

  /* TEST FOR NEW CONVERSATION */

  QPushButton *button = new QPushButton(tr("New Conversation"));
  connect(button, SIGNAL(released()), this, SLOT(addTab()));

  /* */

  mainLayout->addWidget(button);
  mainLayout->addWidget(fileNameLabel);
  mainLayout->addStretch(1);
  setLayout(mainLayout);
}

void Contact::addTab()
{
  _main->addTab("new");
}
