//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Wed Oct 14 12:00:46 2015 Nicolas Charvoz
//

#include "LoginWidget.hh"
#include "MainWidget.hh"
#include "../app/User/PTUser.hh"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
  _mainLayout = new QGridLayout;
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

  _mainLayout->addWidget(labelUsername, 0, 0);
  _mainLayout->addWidget(_editUsername, 0, 1);
  _mainLayout->addWidget(labelPassword, 1, 0);
  _mainLayout->addWidget(_editPassword, 1, 1);
  _mainLayout->addWidget(buttons, 2, 0, 1, 2);
  setLayout(_mainLayout);
}

void LoginWidget::clearLayout(QLayout *layout)
{
  QLayoutItem *item;

  while((item = layout->takeAt(0))) {
    if (item->layout()) {
      clearLayout(item->layout());
      delete item->layout();
    }
    if (item->widget()) {
      delete item->widget();
    }
    delete item;
  }
}

void LoginWidget::validateLogin(int error)
{
  if (error == 0)
    std::cout << "Login bon" << std::endl;
}

void validateLogin2(int error)
{
  if (error == 0)
    std::cout << "Login bon" << std::endl;
}

void LoginWidget::checkLogin()
{
  MainWidget *widget = new MainWidget();
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QMovie *movie = new QMovie("./gui/loader.gif");
  QLabel *processLabel = new QLabel(this);
  std::string userString;
  std::string passString;

  processLabel->setMovie(movie);
  movie->start();

  userString = user.toUtf8().constData();
  passString = pass.toUtf8().constData();

    /* CLEAR THE LAYOUT TO DISPLAY THE LOADER */
  // this->clearLayout(_mainLayout);
  // _mainLayout->addWidget(processLabel, 0, 1);
  // setLayout(_mainLayout);
  /* _______ */
  g_PTUser.logUser(this, &LoginWidget::validateLogin);

  widget->setAttribute(Qt::WA_DeleteOnClose);

  if (userString == "toto" && passString == "toto")
    {
      widget->show();
      deleteLater();
    }
}
