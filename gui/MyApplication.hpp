//
// MyApplication.hpp for  in /home/nicolaschr/rendu/cpp_plazza/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Apr 21 15:26:58 2015 Nicolas Charvoz
// Last update Tue Oct  6 23:47:18 2015 Nicolas Charvoz
//

#ifndef MYAPPLICATION_HPP_
# define MYAPPLICATION_HPP_

# include <string>
# include <iostream>
# include <QApplication>
# include <QDebug>

class MyApplication : public QApplication {

public:

  MyApplication(int argc, char **av) : QApplication(argc, av) {}
  virtual ~MyApplication() {}
  virtual bool notify(QObject *rec, QEvent *ev) {
    try {
      return QApplication::notify(rec, ev);
    }
    catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      exit(0);
    }
    return false;
  }
};

#endif
