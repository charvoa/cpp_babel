//
// main.cpp for  in /home/nicolaschr/rendu/test/babel/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Sep 20 20:19:52 2015 Nicolas Charvoz
// Last update Sun Nov  8 19:29:25 2015 Nicolas Charvoz
//

#include "./User/PTUser.hh"

int		main(int ac, char **av)
{
  std::srand(std::time(0));
  return g_PTUser.run(ac, av);
}
