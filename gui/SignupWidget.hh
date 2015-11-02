//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Signup   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Mon Nov  2 16:23:45 2015 Nicolas Charvoz
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
# include <regex>

class SignupWidget : public QWidget {
Q_OBJECT
public:
  explicit SignupWidget(QWidget *parent = 0);
  void clearLayout(QLayout*);
  void displayButton();
  void refreshUI();

public slots:

  void canDisplayHome(int error);
  void checkSignup();
  void errorString(QString er) {
    std::cout << "Error : " << er.toUtf8().constData() << std::endl;
  }
  void displayIP();

private:

  //Var
  QGridLayout *_mainLayout;
  QLineEdit *_editUsername;
  QLineEdit *_editPassword;
  QLineEdit *_editC;
  bool _login;
  QDialogButtonBox *_buttons;
  QComboBox *_avatarCombo;
  QLineEdit *_editIp;
  bool _dispIp;
};

#endif
