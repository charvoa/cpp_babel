#include "PTUser.hh"
#include <iostream>

void	checkLogin(int error)
{
  std::cout << error << std::endl;
}

int	main()
{
  g_PTUser.logIn(&checkLogin);
}
