//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Wed Oct 14 16:06:55 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact,
			   QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  QLabel *name = new QLabel(tr("Miranda Kerr"), this);


  /* Image */
  QPixmap profilPicture("./gui/miranda2.jpg");
  QLabel *imgP = new QLabel(this);

  imgP->setPixmap(profilPicture);
  /* --- */

  /* MOVE */
  imgP->setGeometry(0, 0, 550, 360);
  name->setGeometry(0, 360, 160, 50);
  /* --- ¨*/

}
