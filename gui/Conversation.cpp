//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Fri Oct  9 14:25:48 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact, QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  QVBoxLayout *mainLayout = new QVBoxLayout;

  QLabel *fileNameLabel = new QLabel(tr(_contact.c_str()));

  mainLayout->addWidget(fileNameLabel);
  setLayout(mainLayout);
}
