//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Sun Nov  8 18:14:28 2015 Nicolas Charvoz
//

#ifndef MAINWIDGET_HH_
# define MAINWIDGET_HH_

# include <QApplication>
# include <QObject>
# include <QFont>
# include <QMovie>
# include <QPushButton>
# include <QRadioButton>
# include <QWidget>
# include <QLineEdit>
# include <QTextEdit>
# include <QTextStream>
# include <QLabel>
# include <QImage>
# include <QTabWidget>
# include <QTabBar>
# include <QDialogButtonBox>
# include <QVBoxLayout>
# include <QGridLayout>
# include <QHBoxLayout>
# include <QFile>
# include <QThread>
# include <QMessageBox>
# include <QScrollArea>
# include <sstream>
# include <iostream>
# include <fstream>

class MainWidget : public QWidget {
Q_OBJECT
public:
  explicit MainWidget(QWidget *parent = 0);
  void addTab(const std::string&);

public slots:
  void closeTab(int);
  void receivedCall(const std::string&);
private:
  QTabWidget *_tabWidget;
};

#endif
