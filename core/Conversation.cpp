//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Tue Sep 29 20:57:04 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact, QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  QLabel *fileNameLabel = new QLabel(tr(_contact.c_str()));

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(fileNameLabel);
  mainLayout->addStretch(1);
  setLayout(mainLayout);
}
