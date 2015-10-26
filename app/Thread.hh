//
// Worker.hh for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Oct 18 14:30:56 2015 Nicolas Charvoz
// Last update Mon Oct 26 03:23:44 2015 Antoine Garcia
//

#ifndef THREAD_HH_
# define THREAD_HH_

#include <QtConcurrent>
#include <iostream>
class Thread {
public:
  Thread()
  {
    std::cout << "THREAD CREATE" << std::endl;
  }
};

#endif
