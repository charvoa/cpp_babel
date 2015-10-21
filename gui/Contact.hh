//
// Home.hh for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:50:07 2015 Nicolas Charvoz
// Last update Wed Oct 21 11:07:36 2015 Nicolas Charvoz
//

#ifndef CONTACT_HH_
# define CONTACT_HH_

# include "MainWidget.hh"
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

class Contact : public QWidget {
Q_OBJECT

public:
  explicit Contact(MainWidget*, QWidget *parent = 0);

public slots:
  void addTab();
  void displayContact();

private:
  MainWidget *_main;

};


#endif
