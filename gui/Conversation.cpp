//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Wed Oct 14 17:35:35 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact,
			   QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  QLabel *name = new QLabel(tr("Miranda Kerr"), this);
  QLineEdit *textZone = new QLineEdit(this);

  QPushButton *sendButton = new QPushButton(tr("Send"), this);
  QWidget *messageZoneTmp = new QWidget(this);
  messageZoneTmp->setStyleSheet("background-color:black;");

  /* Image */
  QPixmap profilPicture("./gui/miranda2.jpg");
  QLabel *imgP = new QLabel(this);

  imgP->setPixmap(profilPicture);
  /* --- */

  /* MOVE */
  imgP->setGeometry(0, 0, 550, 360);
  name->setGeometry(0, 360, 160, 50);
  messageZoneTmp->setGeometry(550, 0, 1370, 920);
  textZone->setGeometry(550, 920, 1120, 100);
  sendButton->setGeometry(1660, 920, 100, 100);
  /* --- ¨*/

}
