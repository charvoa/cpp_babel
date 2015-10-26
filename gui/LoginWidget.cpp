//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Mon Oct 26 03:23:04 2015 Antoine Garcia
//

#include "LoginWidget.hh"
#include "SignupWidget.hh"
#include "MainWidget.hh"
#include "../app/User/PTUser.hh"
#include "../app/Thread.hh"
LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
  QLabel *labelPassword = new QLabel(this);
  QLabel *labelUsername = new QLabel(this);
  _labelIp = new QLabel(this);
  _ipDisplayed = false;

  _buttons = new QDialogButtonBox(this);

  _mainLayout = new QGridLayout;
  setFixedSize(1024, 768);
  setWindowTitle(tr("Login to Spyke"));

  QPixmap pix("./gui/img/spyke.png");
  QLabel *logo = new QLabel(this);
  logo->setPixmap(pix.scaled(250, 250, Qt::KeepAspectRatio));

  _editUsername = new QLineEdit(this);

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editIp = new QLineEdit(this);

  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);
  _labelIp->setText(tr("IP"));
  _editIp->setText(tr("51.254.139.53"));
  _labelIp->setBuddy(_editIp);


  logo->setGeometry(387, -75, 250, 250);
  _mainLayout->addWidget(labelUsername, 0, 0);
  _mainLayout->addWidget(_editUsername, 0, 1);
  _mainLayout->addWidget(labelPassword, 1, 0);
  _mainLayout->addWidget(_editPassword, 1, 1);
  _mainLayout->addWidget(_labelIp, 2, 0);
  _mainLayout->addWidget(_editIp, 2, 1);

  _editIp->hide();
  _labelIp->hide();
  this->displayButton();
  setLayout(_mainLayout);
}

void LoginWidget::refreshUI()
{
  QLabel *labelPassword = new QLabel(this);
  QLabel *labelUsername = new QLabel(this);
  _labelIp = new QLabel(this);
  _buttons = new QDialogButtonBox(this);

  _editUsername = new QLineEdit(this);

  QPixmap pix("./gui/img/spyke.png");
  QLabel *logo = new QLabel(this);
  logo->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editIp = new QLineEdit(this);

  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);
  _labelIp->setText(tr("IP"));
  _labelIp->setBuddy(_editIp);
  _editIp->setText(tr("51.254.139.53"));

  logo->setGeometry(387, -75, 250, 250);
  _mainLayout->addWidget(labelUsername, 0, 0);
  _mainLayout->addWidget(_editUsername, 0, 1);
  _mainLayout->addWidget(labelPassword, 1, 0);
  _mainLayout->addWidget(_editPassword, 1, 1);
  _mainLayout->addWidget(_labelIp, 2, 0);
  _mainLayout->addWidget(_editIp, 2, 1);

  _editIp->hide();
  _labelIp->hide();

  this->displayButton();
}

void LoginWidget::displayButton()
{
  QPushButton *signupButton = new QPushButton(tr("Sign Up"), this);
  QPushButton *displayIP = new QPushButton(tr("Expert mode"), this);

  displayIP->setStyleSheet("background-color: #1DAEF1");
  _buttons->addButton(QDialogButtonBox::Ok);
  _buttons->addButton(QDialogButtonBox::Cancel);
  _buttons->addButton(displayIP, QDialogButtonBox::ActionRole);
  _buttons->addButton(signupButton, QDialogButtonBox::ActionRole);
  _buttons->button(QDialogButtonBox::Ok)->setText(tr("Login"));
  _buttons->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));

  connect(_buttons->button(QDialogButtonBox::Cancel), SIGNAL(released()),
	  this, SLOT(close()));
  connect(_buttons->button(QDialogButtonBox::Ok), SIGNAL(released()),
	  this, SLOT(checkLogin()));
  connect(signupButton, SIGNAL(released()),
	  this, SLOT(signup()));
  connect(displayIP, SIGNAL(released()),
	  this, SLOT(displayIPFunction()));

  _mainLayout->addWidget(_buttons, 3, 0, 1, 2);
}

void LoginWidget::displayIPFunction()
{
  if (_ipDisplayed)
    {
      _editIp->hide();
      _labelIp->hide();
      _editIp->setText(tr("51.254.139.53"));
      _ipDisplayed = false;
    }
  else
    {
      _editIp->show();
      _labelIp->show();
      _editIp->setText(tr("51.254.139.53"));
      _ipDisplayed = true;
    }
}

void LoginWidget::signup()
{
  SignupWidget *sW = new SignupWidget();

  QFile File("./gui/stylesheetLogin.qss");
  File.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(File.readAll());

  /* Applying it */
  sW->setStyleSheet(StyleSheet);

  sW->setAttribute(Qt::WA_DeleteOnClose);
  sW->show();
  deleteLater();
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
      this->clearLayout(_mainLayout);
      this->refreshUI();
      std::cout << "Login fail" << std::endl;
    }
}

void LoginWidget::checkLogin()
{
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QString ip = _editIp->text();
  QMovie *movie = new QMovie("./gui/ring.gif");
  QLabel *processLabel = new QLabel(this);

  processLabel->setMovie(movie);
  movie->start();

  _userString = user.toUtf8().constData();
  _passString = pass.toUtf8().constData();
  _ipString = ip.toUtf8().constData();

  _editPassword->clear();

  this->clearLayout(_mainLayout);
  _mainLayout->addWidget(processLabel, 0, 0, Qt::AlignCenter);
  Thread thread;
  g_PTUser.logUser(*this, &LoginWidget::validateLogin, _userString,
		   _passString, _ipString);

}
