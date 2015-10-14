//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Wed Oct 14 19:10:41 2015 Nicolas Charvoz
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
# include <unistd.h>

class LoginWidget : public QWidget {
Q_OBJECT
public:
  explicit LoginWidget(QWidget *parent = 0);
  void clearLayout(QLayout*);
  void validateLogin(int);
public slots:

  void checkLogin();
private:

  QGridLayout *_mainLayout;
  QLineEdit *_editUsername;
  QLineEdit *_editPassword;
  QLineEdit *_editIp;
};

#endif
