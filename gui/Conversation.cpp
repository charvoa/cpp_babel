//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Thu Oct  8 00:10:56 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact, QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  QLabel *fileNameLabel = new QLabel(tr(_contact.c_str()), this);

  QVBoxLayout *mainLayout = new QVBoxLayout;
}
