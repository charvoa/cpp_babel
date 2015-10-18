//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Sun Oct 18 14:24:28 2015 Nicolas Charvoz
//

#include "LoginWidget.hh"
#include "MainWidget.hh"
#include "../app/User/PTUser.hh"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
  QLabel *labelPassword = new QLabel(this);
  QLabel *labelUsername = new QLabel(this);
  QLabel *labelIp = new QLabel(this);
  QDialogButtonBox *buttons = new QDialogButtonBox(this);

  _login = false;
  _mainLayout = new QGridLayout;
  setFixedSize(800, 600);
  setWindowTitle(tr("Login to Babel"));

  _editUsername = new QLineEdit(this);

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editIp = new QLineEdit(this);

  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);
  labelIp->setText(tr("IP"));
  labelIp->setBuddy(_editIp);

  buttons->addButton(QDialogButtonBox::Ok);
  buttons->addButton(QDialogButtonBox::Cancel);
  buttons->button(QDialogButtonBox::Ok)->setText(tr("Login"));
  buttons->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));

  connect(buttons->button(QDialogButtonBox::Cancel), SIGNAL(released()),
	  this, SLOT(close()));
  connect(buttons->button(QDialogButtonBox::Ok), SIGNAL(released()),
	  this, SLOT(checkLogin()));

  _mainLayout->addWidget(labelUsername, 0, 0);
  _mainLayout->addWidget(_editUsername, 0, 1);
  _mainLayout->addWidget(labelPassword, 1, 0);
  _mainLayout->addWidget(_editPassword, 1, 1);
  _mainLayout->addWidget(labelIp, 2, 0);
  _mainLayout->addWidget(_editIp, 2, 1);

  _mainLayout->addWidget(buttons, 3, 0, 1, 2);
  setLayout(_mainLayout);
}

void LoginWidget::clearLayout(QLayout *layout)
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

void LoginWidget::validateLogin(int error)
{
  MainWidget *widget;

  if (error == 1)
    {
      widget = new MainWidget();
      widget->setAttribute(Qt::WA_DeleteOnClose);
      widget->show();
      deleteLater();
    }
  else
    {
      _login = false;
      std::cout << "Login fail" << std::endl;
    }
}

void LoginWidget::checkLogin()
{
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QString ip = _editIp->text();
  QMovie *movie = new QMovie("./gui/loader.gif");
  QLabel *processLabel = new QLabel(this);

  processLabel->setMovie(movie);
  movie->start();

  _userString = user.toUtf8().constData();
  _passString = pass.toUtf8().constData();
  _ipString = ip.toUtf8().constData();

  _editPassword->clear();

  g_PTUser.logUser(*this, &LoginWidget::validateLogin, _userString,
		   _passString, _ipString);

  /* CLEAR THE LAYOUT TO DISPLAY THE LOADER */
  this->clearLayout(_mainLayout);
  _mainLayout->addWidget(processLabel, 0, 1);
  setLayout(_mainLayout);
  /* _______ */

}
