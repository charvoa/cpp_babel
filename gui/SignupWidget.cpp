//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Sun Oct 25 11:26:52 2015 Nicolas Charvoz
//

#include "SignupWidget.hh"
#include "MainWidget.hh"
#include "LoginWidget.hh"
#include "../app/User/PTUser.hh"

SignupWidget::SignupWidget(QWidget *parent) : QWidget(parent)
{
  QLabel *labelPassword = new QLabel(this);
  QLabel *labelUsername = new QLabel(this);
  QLabel *labelIp = new QLabel(this);
  _buttons = new QDialogButtonBox(this);

  /* COMBO BOX AVATAR */
  _avatarCombo = new QComboBox(this);

  std::stringstream ss;
  for (int i = 1; i < 8; i++)
    {
      ss << "./gui/img/avatar" << i << ".png";
      QPixmap pixmap(ss.str().c_str());
      QIcon icon(pixmap);
      ss.str("");
      ss.clear();
      ss << "Avatar " << i;
      _avatarCombo->addItem(icon, tr(ss.str().c_str()));
      ss.str("");
      ss.clear();
    }
  /* END */

  _login = false;
  _mainLayout = new QGridLayout;
  setFixedSize(1024, 768);
  setWindowTitle(tr("Signup to Babel"));

  _editUsername = new QLineEdit(this);

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editC = new QLineEdit(this);
  _editC->setEchoMode(QLineEdit::Password);

  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);
  labelIp->setText(tr("Confirm Password"));
  labelIp->setBuddy(_editC);

  _mainLayout->addWidget(_avatarCombo, 0, 1);
  _mainLayout->addWidget(labelUsername, 1, 0);
  _mainLayout->addWidget(_editUsername, 1, 1);
  _mainLayout->addWidget(labelPassword, 2, 0);
  _mainLayout->addWidget(_editPassword, 2, 1);
  _mainLayout->addWidget(labelIp, 3, 0);
  _mainLayout->addWidget(_editC, 3, 1);

  this->displayButton();
  setLayout(_mainLayout);
}

void SignupWidget::refreshUI()
{
  QLabel *labelPassword = new QLabel(this);
  QLabel *labelUsername = new QLabel(this);
  QLabel *labelIp = new QLabel(this);
  _buttons = new QDialogButtonBox(this);

  /* COMBO BOX AVATAR */
  _avatarCombo = new QComboBox(this);

  std::stringstream ss;
  for (int i = 1; i < 8; i++)
    {
      ss << "./gui/img/avatar" << i << ".png";
      QPixmap pixmap(ss.str().c_str());
      QIcon icon(pixmap);
      ss.str("");
      ss.clear();
      ss << "Avatar " << i;
      _avatarCombo->addItem(icon, tr(ss.str().c_str()));
      ss.str("");
      ss.clear();
    }
  // END

  _editUsername = new QLineEdit(this);
  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editC = new QLineEdit(this);
  _editC->setEchoMode(QLineEdit::Password);

  labelUsername->setText(tr("Username"));
  labelUsername->setBuddy(_editUsername);
  labelPassword->setText(tr("Password"));
  labelPassword->setBuddy(_editPassword);
  labelIp->setText(tr("Confirm Password"));
  labelIp->setBuddy(_editC);

  _mainLayout->addWidget(_avatarCombo, 0, 1);
  _mainLayout->addWidget(labelUsername, 1, 0);
  _mainLayout->addWidget(_editUsername, 1, 1);
  _mainLayout->addWidget(labelPassword, 2, 0);
  _mainLayout->addWidget(_editPassword, 2, 1);
  _mainLayout->addWidget(labelIp, 3, 0);
  _mainLayout->addWidget(_editC, 3, 1);

  this->displayButton();
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

  _mainLayout->addWidget(_buttons, 4, 0, 1, 2);
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
  QMessageBox msgBox;
  bool _okClicked = false;
  LoginWidget *login;
  login = new LoginWidget();

  QFile File2("./gui/stylesheetLogin.qss");
  File2.open(QFile::ReadOnly);
  QString StyleSheet2 = QLatin1String(File2.readAll());

  /* Applying it */
  login->setStyleSheet(StyleSheet2);

  if (error == 1)
    {
      msgBox.setText("Yeah ! You're part of the team now :)");
      msgBox.exec();
      login->show();
      deleteLater();
    }
  else
    {
      msgBox.setText("Oh no it didn't work :'(");
      msgBox.exec();
    }
}

void SignupWidget::checkSignup()
{
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QString c = _editC->text();
  QMovie *movie = new QMovie("./gui/ring.gif");
  QLabel *processLabel = new QLabel(this);

  processLabel->setMovie(movie);
  movie->start();

  _userString = user.toUtf8().constData();
  _passString = pass.toUtf8().constData();
  _cString = c.toUtf8().constData();

  _editPassword->clear();
  _editC->clear();

  QString cb = _avatarCombo->currentText();

  std::cout << "He chose " << cb.toUtf8().constData() << std::endl;

  this->clearLayout(_mainLayout);
  _mainLayout->addWidget(processLabel, 0, 0, Qt::AlignCenter);

  g_PTUser.signup(*this, &SignupWidget::validateSignup, _userString,
  		   _passString, _cString);
  /* ADD AVATAR CHOICE IN THE FUNCTION */
}
