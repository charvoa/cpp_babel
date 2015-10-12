//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Sun Oct 11 19:07:14 2015 Nicolas Charvoz
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

public slots:

  void checkLogin();

private:

  QLineEdit *_editUsername;
  QLineEdit *_editPassword;
};

#endif
