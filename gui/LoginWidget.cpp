//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Fri Oct  9 14:50:12 2015 Nicolas Charvoz
//

#include "LoginWidget.hh"
#include "MyWidget.hh"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
  QGridLayout *mainLayout = new QGridLayout;
  QLabel *labelPassword;
  QLabel *labelUsername;
  QLineEdit *editUsername;
  QLineEdit *editPassword;
  QDialogButtonBox *buttons;

  setFixedSize(800, 600);
  setWindowTitle(tr("Login to Babel"));

  editUsername = new QLineEdit(this);

  editPassword = new QLineEdit(this);
  editPassword->setEchoMode(QLineEdit::Password);

  labelUsername = new QLabel(this);
  labelPassword = new QLabel(this);
  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(editPassword);

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
  mainLayout->addWidget(editUsername, 0, 1);
  mainLayout->addWidget(labelPassword, 1, 0);
  mainLayout->addWidget(editPassword, 1, 1);
  mainLayout->addWidget(buttons, 2, 0, 1, 2);
  setLayout(mainLayout);
}

void LoginWidget::checkLogin()
{
  MyWidget *widget = new MyWidget();

  widget->setAttribute(Qt::WA_DeleteOnClose);
  widget->show();
  deleteLater();
}
