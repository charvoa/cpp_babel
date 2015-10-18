//
// Loader.cpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Oct 18 10:19:44 2015 Nicolas Charvoz
// Last update Sun Oct 18 11:31:09 2015 Nicolas Charvoz
//

#include "Loader.hpp"

Loader::Loader()
{
}

Loader::~Loader()
{
}

void Loader::process(QWidget *o)
{
  qDebug("Hello world");
  std::cout << typeid(o).name() << "\t" << "o" << std::endl;
  emit finished();
}
