//
// main.cpp for  in /home/nicolaschr/rendu/test/babel/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Sep 20 20:19:52 2015 Nicolas Charvoz
// Last update Sun Sep 20 20:26:52 2015 Nicolas Charvoz
//

#include "../core/MyApplication.hpp"
#include "../core/MyWidget.hh"


int		main(int ac, char **av)
{
  MyApplication app(ac, av);
  MyWidget widget;

  widget.show();

  return app.exec();
}
