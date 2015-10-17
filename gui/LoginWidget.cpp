//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Wed Oct 14 19:31:31 2015 Nicolas Charvoz
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
  if (error == 1)
    {
      _login = true;
      std::cout << "Login bon" << std::endl;
    }
  else
    {
      _login = false;
      std::cout << "Login fail" << std::endl;
    }
}

void LoginWidget::checkLogin()
{
  MainWidget *widget = new MainWidget();
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QMovie *movie = new QMovie("./gui/loader.gif");
  QLabel *processLabel = new QLabel(this);

  processLabel->setMovie(movie);
  movie->start();

  _userString = user.toUtf8().constData();
  _passString = pass.toUtf8().constData();

  g_PTUser.logUser(*this, &LoginWidget::validateLogin);

  /* CLEAR THE LAYOUT TO DISPLAY THE LOADER */
  // this->clearLayout(_mainLayout);
  // _mainLayout->addWidget(processLabel, 0, 1);
  // setLayout(_mainLayout);
  /* _______ */

  widget->setAttribute(Qt::WA_DeleteOnClose);

  if (_login)
    {
      widget->show();
      deleteLater();
    }
}
