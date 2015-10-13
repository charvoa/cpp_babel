//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Tue Oct 13 14:40:29 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact,
			   QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  //  QVBoxLayout *mainLayout = new QVBoxLayout;
  QLabel *fileNameLabel = new QLabel(tr(_contact.c_str()));
  QTextEdit *messageZone = new QTextEdit;
  QGridLayout *gridMessage = new QGridLayout;
  QPushButton *sendMessage = new QPushButton(tr("Send"));


  gridMessage->addWidget();
  setLayout(mainLayout);
}
