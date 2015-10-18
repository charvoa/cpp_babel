#ifndef PTUSER_HH_
# define PTUSER_HH_

#include <iostream>
#include <string>
#include "../Network/NetworkServerHandler.hh"

class PTUser
{
private:
  class User
  {
     friend class PTUser;
    std::string _username;
    std::string _password;
  protected:
    std::string _objectId;
  public:
    User();
    ~User();
    const std::string &getUsername() const;
    const std::string &getObjectId() const;
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
    std::cout << _currentUser._objectId << std::endl;
    if (server.start("localhost", 4040) == -1)
      (obj.*call)(0);
    else{
      (obj.*call)(1);
    }
  }
};

extern PTUser g_PTUser;
#endif
