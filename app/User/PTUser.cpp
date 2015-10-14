#include "PTUser.hh"
#include <iostream>

PTUser g_PTUser;
PTUser::PTUser()
{
  std::cout << "Coucou" << std::endl;
}

PTUser::~PTUser()
{
  std::cout << "Destroy" << std::endl;
}

void	PTUser::test()
{
  std::cout << "TESTOR" << std::endl;
}

void	PTUser::logIn(Callback func)
{
  std::cout << "Process LOGIN" << std::endl;
  func(1);
}

template<typename T>
void	PTUser::logUser(T obj, void(T::*call)(int))
{
  std::cout << "PROCESSING LOGIN USER..." << std::endl;
  (obj.*call)(1);
}

PTUser::User::User()
{
  std::cout << "User Create" << std::endl;
}

PTUser::User::~User()
{
  std::cout << "Destroy User" << std::endl;
}
