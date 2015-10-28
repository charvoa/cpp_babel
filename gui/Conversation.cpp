//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Wed Oct 28 15:09:51 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact,
			   QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  QLabel *name = new QLabel(tr(contact.c_str()), this);
  QLineEdit *textZone = new QLineEdit(this);

  QPushButton *sendButton = new QPushButton(tr("Send"), this);
  QTextEdit *messageZoneTmp = new QTextEdit(this);
  QFont f("Calibri", 10, QFont::Bold);
  name->setFont(f);

  messageZoneTmp->setStyleSheet("background-color:white;");
  messageZoneTmp->setReadOnly(true);

  messageZoneTmp->append(tr("14h28 : \nSalut beau gosse"));

  /* Image */
  QPixmap profilPicture("./gui/img/avatar1.png");
  QLabel *imgP = new QLabel(this);

  imgP->setPixmap(profilPicture.scaled(432, 432, Qt::KeepAspectRatio));
  /* --- */

  int imgHeight = 432;
  int imgWidth = 432;

  /* MOVE */
  imgP->setGeometry(0, 0, imgHeight, imgWidth);
  name->setGeometry(10, imgHeight + 10, 160, 50);
  messageZoneTmp->setGeometry(imgWidth, 0, 1370, 920);
  textZone->setGeometry(imgWidth, 920, 1120, 100);
  sendButton->setGeometry(1660, 920, 100, 100);
  /* --- ¨*/

}
