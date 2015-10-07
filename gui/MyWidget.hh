//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Wed Oct  7 15:48:22 2015 Nicolas Charvoz
//

#ifndef MYWIDGET_HH_
# define MYWIDGET_HH_

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

class MyWidget : public QWidget {
Q_OBJECT
public:
  explicit MyWidget(QWidget *parent = 0);

public slots:
  void closeTab(int);
private:
  QTabWidget *_tabWidget;
};

#endif
