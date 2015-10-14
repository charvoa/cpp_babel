#ifndef PTUSER_HH_
# define PTUSER_HH_

#include <string>

typedef void (*Callback)(int error);

class PTUser
{
private:
  class User
  {
    std::string _username;
    std::string _password;
  public:
    User();
    ~User();
  };
  User	_currentUser;
public:
  PTUser();
  ~PTUser();
  void logIn(Callback func);
  void signup(Callback func);
  void	test();
  User&		currentUser();
  template<typename T>
  void logUser(T obj, void(T::*call)(int));
};

extern PTUser g_PTUser;
#endif