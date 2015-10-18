//
// Worker.hh for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Oct 18 10:18:18 2015 Nicolas Charvoz
// Last update Sun Oct 18 11:11:56 2015 Nicolas Charvoz
//

#ifndef LOADER_HH_
# define LOADER_HH_

# include "MainWidget.hh"
# include <typeinfo>

class Loader : public QObject {
  Q_OBJECT

public:
  Loader();
  ~Loader();

public slots:

  void process();
  // template <typename T>
  // void process(T &c)
  // {
  //   std::cout << typeid(c).name() << "\t" << "c" << std::endl;
  // }

signals:
  void finished();
  void error(QString er);


};

#endif
