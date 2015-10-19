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

PTUser::User&	PTUser::currentUser()
{
  return (_currentUser);
}

//Nested Class User
PTUser::User::User()
{
  std::cout << "User Create" << std::endl;
}

PTUser::User::~User()
{
  std::cout << "Destroy User" << std::endl;
}

const std::string	&PTUser::User::getUsername() const
{
  return (_username);
}

const std::string	&PTUser::User::getObjectId() const
{
  return (_objectId);
}
