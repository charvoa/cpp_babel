//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Signup   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Sun Oct 25 01:22:25 2015 Nicolas Charvoz
//

#ifndef SIGNUPWIDGET_HH_
# define SIGNUPWIDGET_HH_

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
# include <QComboBox>
# include <sstream>
# include <iostream>
# include <fstream>

class SignupWidget : public QWidget {
Q_OBJECT
public:
  explicit SignupWidget(QWidget *parent = 0);
  void clearLayout(QLayout*);
  void validateSignup(int);
  void displayButton();
  void refreshUI();
public slots:

  void checkSignup();
  void errorString(QString er) {
    std::cout << "Error : " << er.toUtf8().constData() << std::endl;
  }
private:

  QGridLayout *_mainLayout;
  QLineEdit *_editUsername;
  QLineEdit *_editPassword;
  QLineEdit *_editC;
  bool _login;
  std::string _userString;
  std::string _passString;
  std::string _cString;
  QDialogButtonBox *_buttons;
  QComboBox *_avatarCombo;
};

#endif
