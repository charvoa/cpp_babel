//
// LoginWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Mon Nov  2 14:35:08 2015 Nicolas Charvoz
//

#include "SignupWidget.hh"
#include "MainWidget.hh"
#include "LoginWidget.hh"
#include "../app/User/PTUser.hh"

SignupWidget::SignupWidget(QWidget *parent) : QWidget(parent)
{
  _buttons = new QDialogButtonBox(this);

  _dispIp = false;
  /* COMBO BOX AVATAR */
  _avatarCombo = new QComboBox(this);

  connect(&g_PTUser, SIGNAL(canDisplayHome(int)), this, SLOT(canDisplayHome(int)));

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
  setWindowTitle(tr("Signup to Spyke"));

  _editUsername = new QLineEdit(this);

  _editPassword = new QLineEdit(this);
  _editPassword->setEchoMode(QLineEdit::Password);

  _editUsername->setPlaceholderText(tr("Username"));
  _editPassword->setPlaceholderText(tr("Password"));

  _editC = new QLineEdit(this);
  _editC->setEchoMode(QLineEdit::Password);
  _editC->setPlaceholderText(tr("Confirm Password"));

  _editIp = new QLineEdit(this);
  _editIp->setText(tr("51.254.139.53:4040"));
  _editIp->setPlaceholderText(tr("IP:Port"));

  _mainLayout->addWidget(_avatarCombo, 0, 0);
  _mainLayout->addWidget(_editUsername, 1, 0);
  _mainLayout->addWidget(_editPassword, 2, 0);
  _mainLayout->addWidget(_editC, 3, 0);
  _mainLayout->addWidget(_editIp, 4, 0);

  _editIp->hide();
  this->displayButton();
  setLayout(_mainLayout);
}

void SignupWidget::refreshUI()
{
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

  _editUsername->setPlaceholderText(tr("Username"));
  _editPassword->setPlaceholderText(tr("Password"));
  _editC->setPlaceholderText(tr("Confirm Password"));

  _editIp = new QLineEdit(this);
  _editIp->setText(tr("51.254.139.53:4040"));
  _editIp->setPlaceholderText(tr("IP:Port"));

  _mainLayout->addWidget(_avatarCombo, 0, 0);
  _mainLayout->addWidget(_editUsername, 1, 0);
  _mainLayout->addWidget(_editPassword, 2, 0);
  _mainLayout->addWidget(_editC, 3, 0);
  _mainLayout->addWidget(_editIp, 4, 0);

  _editIp->hide();
  this->displayButton();
}

void SignupWidget::displayButton()
{
  QPushButton *b = new QPushButton(tr("Expert mode"), this);

  b->setStyleSheet("background-color: #1DAEF1");
  _buttons->addButton(QDialogButtonBox::Ok);
  _buttons->addButton(QDialogButtonBox::Cancel);
  _buttons->button(QDialogButtonBox::Ok)->setText(tr("Signup"));
  _buttons->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));
  _buttons->addButton(b, QDialogButtonBox::ActionRole);

  connect(b, SIGNAL(released()), this, SLOT(displayIP()));
  connect(_buttons->button(QDialogButtonBox::Cancel), SIGNAL(released()),
	  this, SLOT(close()));
  connect(_buttons->button(QDialogButtonBox::Ok), SIGNAL(released()),
	  this, SLOT(checkSignup()));

  _mainLayout->addWidget(_buttons, 5, 0, 1, 2);
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

void SignupWidget::displayIP()
{
  if (_dispIp)
    {
      _editIp->hide();
      _editIp->setText(tr("51.254.139.53:4040"));
      _dispIp = false;
    }
  else
    {
      _editIp->setText(tr("51.254.139.53:4040"));
      _editIp->show();
      _dispIp = true;
    }
}

void SignupWidget::canDisplayHome(int error)
{
  QMessageBox msgBox;
  MainWidget *main;
  main = new MainWidget();

  QFile File2("./gui/stylesheet.qss");
  File2.open(QFile::ReadOnly);
  QString StyleSheet2 = QLatin1String(File2.readAll());

  /* Applying it */
  main->setStyleSheet(StyleSheet2);

  if (error == 1)
    {
      msgBox.setText("Yeah ! You're part of the team now :)");
      msgBox.exec();
      main->show();
      deleteLater();
    }
  else if (error == PASSWORD_DONT_MATCH)
    {
      msgBox.setText("The password don't match !");
      msgBox.exec();
      this->refreshUI();
      return;
    }
  else
    {
      msgBox.setText("Oh no it didn't work ! Try again ! :'(");
      msgBox.exec();
      this->refreshUI();
      return;
    }
}

void SignupWidget::checkSignup()
{
  std::string _userString;
  std::string _passString;
  std::string _cString;
  std::string _ipString;
  QString user = _editUsername->text();
  QString pass = _editPassword->text();
  QString c = _editC->text();
  QString ip = _editIp->text();
  QMovie *movie = new QMovie("./gui/ring.gif");
  QLabel *processLabel = new QLabel(this);

  processLabel->setMovie(movie);
  movie->start();

  _userString = user.toUtf8().constData();
  _passString = pass.toUtf8().constData();
  _cString = c.toUtf8().constData();
  _ipString = ip.toUtf8().constData();

  if (_userString == ""|| _passString == "" || _cString == "" || _ipString == "")
    {
      QMessageBox *msgBox = new QMessageBox(this);

      msgBox->setText("You must enter valid character in the fileds");
      msgBox->exec();
    }
  else
    {
      _editPassword->clear();
      _editC->clear();

      QString cb = _avatarCombo->currentText();

      std::string cbString = cb.toUtf8().constData();

      std::cout << "He chose " << cbString.back() << std::endl;

      this->clearLayout(_mainLayout);
      _mainLayout->addWidget(processLabel, 0, 0, Qt::AlignCenter);
      g_PTUser.signup(_userString, _passString, _cString, _ipString,
		      cbString.back());
    }
  /* ADD AVATAR CHOICE IN THE FUNCTION */
}
