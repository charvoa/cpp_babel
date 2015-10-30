//
// Home.hh for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:50:07 2015 Nicolas Charvoz
// Last update Wed Oct 28 15:54:44 2015 Nicolas Charvoz
//

#ifndef UICONTACT_HH_
# define UICONTACT_HH_

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
# include "MainWidget.hh"
# include "../app/User/PTUser.hh"

class UiContact : public QWidget {

Q_OBJECT

public:
  explicit UiContact(QWidget *parent = 0);

public slots:
  void addTab();
  void displayContact();
  void refreshUI();

private:
  MainWidget *_main;

};


#endif
