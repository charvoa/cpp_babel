//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Mon Oct 19 10:49:41 2015 Nicolas Charvoz
//

#include "SignupWidget.hh"
#include "MainWidget.hh"
#include "../app/User/PTUser.hh"

SignupWidget::SignupWidget(QWidget *parent) : QWidget(parent)
{
  QLabel *labelPassword = new QLabel(this);
  QLabel *labelUsername = new QLabel(this);
  QLabel *labelIp = new QLabel(this);
  _buttons = new QDialogButtonBox(this);

  _login = false;
  _mainLayout = new QGridLayout;
  setFixedSize(800, 600);
  setWindowTitle(tr("Signup to Babel"));

  _editUsername = new QLineEdit(this);

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editC = new QLineEdit(this);

  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);
  labelIp->setText(tr("Confirm Password"));
  labelIp->setBuddy(_editC);


  _mainLayout->addWidget(labelUsername, 0, 0);
  _mainLayout->addWidget(_editUsername, 0, 1);
  _mainLayout->addWidget(labelPassword, 1, 0);
  _mainLayout->addWidget(_editPassword, 1, 1);
  _mainLayout->addWidget(labelIp, 2, 0);
  _mainLayout->addWidget(_editC, 2, 1);

  this->displayButton();
  setLayout(_mainLayout);
}

void SignupWidget::displayButton()
{
  _buttons->addButton(QDialogButtonBox::Ok);
  _buttons->addButton(QDialogButtonBox::Cancel);
  _buttons->button(QDialogButtonBox::Ok)->setText(tr("Signup"));
  _buttons->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));

  connect(_buttons->button(QDialogButtonBox::Cancel), SIGNAL(released()),
	  this, SLOT(close()));
  connect(_buttons->button(QDialogButtonBox::Ok), SIGNAL(released()),
	  this, SLOT(checkSignup()));

  _mainLayout->addWidget(_buttons, 3, 0, 1, 2);
}

void SignupWidget::clearLayout(QLayout *layout)
{
  QLayoutItem *item;

  while((item = layout->takeAt(0)))
    {
    if (item->layout())
      {
	clearLayout(item->layout());
	delete item->layout();
      }
    if (item->widget())
      {
	delete item->widget();
      }
    delete item;
    }
}

void SignupWidget::validateSignup(int error)
{
}

void SignupWidget::checkSignup()
{
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QString c = _editC->text();
  QMovie *movie = new QMovie("./gui/ajax-loader.gif");
  QLabel *processLabel = new QLabel(this);

  processLabel->setMovie(movie);
  movie->start();

  _userString = user.toUtf8().constData();
  _passString = pass.toUtf8().constData();
  _cString = c.toUtf8().constData();

  _editPassword->clear();
  _editC->clear();

  _mainLayout->addWidget(processLabel, 3, 0);

  // g_PTUser.logUser(*this, &SignupWidget::validateSignup, _userString,
  // 		   _passString, _cString);

  delete(_buttons);
}
