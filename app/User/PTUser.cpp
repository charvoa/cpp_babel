#include "PTUser.hh"
#include <iostream>

PTUser g_PTUser;
PTUser::PTUser()
{
  std::cout << "PTUSER CREATED" << std::endl;
}

PTUser::~PTUser()
{
  std::cout << "Destroy" << std::endl;
}

PTUser::User::User()
{
  std::cout << "User Create" << std::endl;
}

PTUser::User::~User()
{
  std::cout << "Destroy User" << std::endl;
}
