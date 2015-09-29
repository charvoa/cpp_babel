//
// Contact.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Tue Sep 29 17:17:05 2015 Nicolas Charvoz
//

#include "Contact.hh"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
  QLabel *fileNameLabel = new QLabel(tr("Contact"));

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(fileNameLabel);
  mainLayout->addStretch(1);
  setLayout(mainLayout);
}
