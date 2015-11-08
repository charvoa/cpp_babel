//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Sat Nov  7 16:10:21 2015 Nicolas Charvoz
//

#include "LoginWidget.hh"
#include "SignupWidget.hh"
#include "MainWidget.hh"
#include "../app/User/PTUser.hh"
#include "../app/Thread.hh"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
  connect(&g_PTUser, SIGNAL(canDisplayHome(int)), this, SLOT(canDisplayHome(int)));
  _ipDisplayed = false;

  _buttons = new QDialogButtonBox(this);

  _mainLayout = new QGridLayout;
  setFixedSize(1024, 768);
  setWindowTitle(tr("Login to Spyke"));

  QPixmap pix("./gui/img/spyke_blue.png");
  QLabel *logo = new QLabel(this);
  logo->setPixmap(pix.scaled(250, 250, Qt::KeepAspectRatio));

  _editUsername = new QLineEdit(this);
  _editUsername->setPlaceholderText(tr("Username"));

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);
  _editPassword->setPlaceholderText(tr("Password"));

  _editIp = new QLineEdit(this);
  _editIp->setPlaceholderText(tr("IP:port"));

  _editIp->setText(tr("51.254.139.53:4040"));

  logo->setGeometry(387, -75, 250, 250);
  _mainLayout->addWidget(_editUsername, 0, 0);
  _mainLayout->addWidget(_editPassword, 1, 0);
  _mainLayout->addWidget(_editIp, 2, 0);

  _editIp->hide();
  this->displayButton();
  setLayout(_mainLayout);
}

void LoginWidget::canDisplayHome(int error)
{
  MainWidget *widget;

  std::cout << error << std::endl;
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
  std::cout << "LOGIN WIDGET CAN DISPLAY HOME" << std::endl;
}

void LoginWidget::refreshUI()
{
  _buttons = new QDialogButtonBox(this);

  _editUsername = new QLineEdit(this);

  QPixmap pix("./gui/img/spyke_blue.png");
  QLabel *logo = new QLabel(this);
  logo->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editIp = new QLineEdit(this);
  _editIp->setText(tr("51.254.139.53:4040"));

  logo->setGeometry(387, -75, 250, 250);
  _mainLayout->addWidget(_editUsername, 0, 0);
  _mainLayout->addWidget(_editPassword, 1, 0);
  _mainLayout->addWidget(_editIp, 2, 0);

  _editIp->hide();

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
      _editIp->setText(tr("51.254.139.53:4040"));
      _ipDisplayed = false;
    }
  else
    {
      _editIp->show();
      _editIp->setText(tr("51.254.139.53:4040"));
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

  if (_userString == "" || _passString == "" || _ipString == "")
    {
      QMessageBox *msgBox = new QMessageBox(this);

      msgBox->setText("Please fill the fields");
      msgBox->exec();
    }
  else
    {
      _editPassword->clear();

      this->clearLayout(_mainLayout);
      _mainLayout->addWidget(processLabel, 0, 0, Qt::AlignCenter);

      g_PTUser.logUser(_userString, _passString, _ipString);
    }
}
