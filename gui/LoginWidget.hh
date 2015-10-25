//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Sun Oct 25 11:22:47 2015 Nicolas Charvoz
//

#ifndef LOGINWIDGET_HH_
# define LOGINWIDGET_HH_

# include <QApplication>
# include <QObject>
# include <QFont>
# include <QPushButton>
# include <QRadioButton>
# include <QWidget>
# include <QLineEdit>
# include <QTextEdit>
# include <QTextStream>
# include <QLabel>
# include <QTabWidget>
# include <QDialogButtonBox>
# include <QVBoxLayout>
# include <QHBoxLayout>
# include <QFile>
# include <sstream>
# include <iostream>
# include <fstream>

class LoginWidget : public QWidget {
Q_OBJECT
public:
  explicit LoginWidget(QWidget *parent = 0);
  void clearLayout(QLayout*);
  void validateLogin(int);
  void displayButton();
  void refreshUI();
public slots:

  void checkLogin();
  void errorString(QString er) {
    std::cout << "Error : " << er.toUtf8().constData() << std::endl;
  }
  void signup();
  void displayIPFunction();
private:

  QGridLayout *_mainLayout;
  QLineEdit *_editUsername;
  QLineEdit *_editPassword;
  QLineEdit *_editIp;
  std::string _userString;
  std::string _passString;
  std::string _ipString;
  QDialogButtonBox *_buttons;
  QLabel *_labelIp;
  bool _ipDisplayed;
};

#endif
