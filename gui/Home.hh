//
// Home.hh for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:50:07 2015 Nicolas Charvoz
// Last update Wed Oct 21 17:34:48 2015 Nicolas Charvoz
//

#ifndef HOME_HH_
# define HOME_HH_

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
# include <string>
# include <sstream>
# include <iostream>
# include <fstream>
# include <curl/curl.h>
# include "MyCurl.hh"

class Home : public QWidget {
Q_OBJECT
public:
  explicit Home(QWidget *parent = 0);
  void validateFriend(int);
  int weatherDisplay();
public slots:
  void addFriend();

private:

  QLineEdit *_addFriend;

};


#endif
