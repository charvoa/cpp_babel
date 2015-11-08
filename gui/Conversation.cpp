//
// Conversation.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Sun Nov  8 14:55:23 2015 Nicolas Charvoz
//

#include "Conversation.hh"

Conversation::Conversation(const std::string &contact,
			   QWidget *parent)
  : QWidget(parent), _contact(contact)
{
  _call = false;
  _first = true;
  QLabel *name = new QLabel(tr(contact.c_str()), this);
  _textZone = new QLineEdit(this);
  _callButton = new QPushButton(this);

  _callButton->setIcon(QIcon("./gui/img/phone61.png"));
  _callButton->setIconSize(QSize(120, 120));

  QPushButton *sendButton = new QPushButton(tr("Send"), this);
  _messageZone = new QTextEdit(this);
  QFont f("Calibri", 10, QFont::Bold);
  name->setFont(f);

  _messageZone->setStyleSheet("background-color:white;");
  _messageZone->setReadOnly(true);

  /* Image */
  std::stringstream pp;

  pp << "./gui/img/avatar"
     << g_PTUser.currentUser().getContactFromName(contact).getPic()
     << ".png";
  QPixmap profilPicture(pp.str().c_str());
  QLabel *imgP = new QLabel(this);

  imgP->setPixmap(profilPicture.scaled(432, 432, Qt::KeepAspectRatio));
  /* --- */

  int imgHeight = 432;
  int imgWidth = 432;

  /* MOVE */
  connect(_callButton, SIGNAL(released()), this, SLOT(functionCall()));
  connect(sendButton, SIGNAL(released()), this, SLOT(functionText()));

  imgP->setGeometry(0, 0, imgHeight, imgWidth);
  name->setGeometry(10, imgHeight + 10, 160, 50);
  _messageZone->setGeometry(imgWidth, 0, 1370, 920);
  _textZone->setGeometry(imgWidth, 920, 1120, 100);
  sendButton->setGeometry(1660, 920, 100, 100);
  _callButton->setGeometry(130, 900, 120, 120);
  /* --- ¨*/
}

void Conversation::functionText()
{
  QString text = _textZone->text();
  time_t currentTime;
  struct tm *localTime;

  time( &currentTime );                   // Get the current time
  localTime = localtime( &currentTime );  // Convert the current time to the local time
  int day    = localTime->tm_mday;
  int month  = localTime->tm_mon + 1;
  int year   = localTime->tm_year + 1900;
  int hour   = localTime->tm_hour;
  int min    = localTime->tm_min;
  int sec    = localTime->tm_sec;

  std::stringstream dateStream;
  std::stringstream timeStream;

  dateStream << day << "/" << month << "/" << year;
  timeStream << hour << ":" << min << ":" << sec;
  QString date = QString::fromStdString(dateStream.str());
  QString time = QString::fromStdString(timeStream.str());
  _textZone->clear();
  if (_first)
    {
      _messageZone->append("--------" + date + "--------");
      _first = false;
    }
  _messageZone->append("\n" + time + "\n" + text + "\n");
}

void Conversation::functionCall()
{
  if (_call == false)
    {
      std::cout << "Making call" << std::endl;
      _callButton->setIcon(QIcon("./gui/img/phone59.png"));
      _callButton->setIconSize(QSize(120, 120));
      _call = true;
    }
  else
    {
      std::cout << "Hanging up call" << std::endl;
      _callButton->setIcon(QIcon("./gui/img/phone61.png"));
      _callButton->setIconSize(QSize(120, 120));
      _call = false;
    }
}
