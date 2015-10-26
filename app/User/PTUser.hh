#ifndef PTUSER_HH_
# define PTUSER_HH_

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include "../Contact/Contact.hh"
#include "../Network/NetworkServerHandler.hh"

class PTUser: public QObject
{
Q_OBJECT
private:
  class User
  {
    friend class PTUser;
    std::string _username;
    std::string _password;
    std::list<Contact *> _contact;
  protected:
    std::string _objectId;
  public:
    User();
    ~User();
    const std::string &getUsername() const;
    const std::string &getObjectId() const;
    const std::list<Contact *>& getContacts() const;
  };
  User	_currentUser;
  NetworkServerHandler server;
  std::string _ipServer;
private slots:
  void userConnected(int check);
public:
  PTUser();
  ~PTUser();
  User&		currentUser();
  int run(int, char**);
  template<typename T>
  void logUser(T &obj, void(T::*call)(int), const std::string &username, const std::string &password, const std::string &ip)
  {
    std::cout << "PROCESSING LOGIN USER..." << std::endl;
    if (server.start("localhost", 4040) == -1) {
      (obj.*call)(0);
    }
  }
  template <typename T>
  void signup(T &obj, void(T::*call)(int), const std::string &username, const std::string &password, const std::string &verify)
  {
    std::cout << "SIGNUP..." << std::endl;
    (obj.*call)(1);
  }
};

extern PTUser g_PTUser;
#endif
