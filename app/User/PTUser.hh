#ifndef PTUSER_HH_
# define PTUSER_HH_

#include <iostream>
#include <string>
#include "../Network/NetworkServerHandler.hh"

typedef void (*Callback)(int error);

class PTUser
{
private:
  class User
  {
    std::string _username;
    std::string _password;
    std::string _objectId;
  public:
    User();
    ~User();
  };
  User	_currentUser;
  NetworkServerHandler server;
  std::string _ipServer;
public:
  PTUser();
  ~PTUser();
  User&		currentUser();
  template<typename T>
  void logUser(T &obj, void(T::*call)(int), const std::string &username, const std::string &password, const std::string &ip)
  {
    std::cout << "PROCESSING LOGIN USER..." << std::endl;
    if (server.start("google.caca", 80) == -1)
      (obj.*call)(0);
    else{
      (obj.*call)(1);
    }
  }
};

extern PTUser g_PTUser;
#endif
