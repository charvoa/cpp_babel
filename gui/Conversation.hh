//
// Home.hh for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:50:07 2015 Nicolas Charvoz
// Last update Tue Sep 29 20:34:11 2015 Nicolas Charvoz
//

#ifndef CONVERSATION_HH_
# define CONVERSATION_HH_

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

class Conversation : public QWidget {
Q_OBJECT

public:
  explicit Conversation(const std::string &contact, QWidget *parent = 0);

public slots:

private:
  std::string _contact;

};


#endif
