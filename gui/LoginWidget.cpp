//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Mon Oct 12 07:52:23 2015 Nicolas Charvoz
//

#include "LoginWidget.hh"
#include "MainWidget.hh"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
  QGridLayout *mainLayout = new QGridLayout;
  QLabel *labelPassword;
  QLabel *labelUsername;
  QDialogButtonBox *buttons;

  setFixedSize(800, 600);
  setWindowTitle(tr("Login to Babel"));

  _editUsername = new QLineEdit(this);

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  labelUsername = new QLabel(this);
  labelPassword = new QLabel(this);
  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);

  buttons = new QDialogButtonBox(this);
  buttons->addButton(QDialogButtonBox::Ok);
  buttons->addButton(QDialogButtonBox::Cancel);
  buttons->button(QDialogButtonBox::Ok)->setText(tr("Login"));
  buttons->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));

  connect(buttons->button(QDialogButtonBox::Cancel), SIGNAL(released()),
	  this, SLOT(close()));
  connect(buttons->button(QDialogButtonBox::Ok), SIGNAL(released()),
	  this, SLOT(checkLogin()));

  mainLayout->addWidget(labelUsername, 0, 0);
  mainLayout->addWidget(_editUsername, 0, 1);
  mainLayout->addWidget(labelPassword, 1, 0);
  mainLayout->addWidget(_editPassword, 1, 1);
  mainLayout->addWidget(buttons, 2, 0, 1, 2);
  setLayout(mainLayout);
}

void LoginWidget::checkLogin()
{
  std::cout << "1L" << std::endl;
  MainWidget *widget;

  std::cout << "3L" << std::endl;
  QString _user = _editUsername->text();
  QString _pass = _editPassword->text();

  std::cout << "7L" << std::endl;
  std::string _userString = _user.toUtf8().constData();
  std::string _passString = _pass.toUtf8().constData();

  std::cout << "username : " << _userString
	    << " password : " << _passString
	    << std::endl;
  widget = new MainWidget();
  widget->setAttribute(Qt::WA_DeleteOnClose);
  if (_userString == "toto" && _passString == "toto")
    {
      widget->show();
      deleteLater();
    }
}
