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
signals:
  void canDisplayHome(int check);
public:
  PTUser();
  ~PTUser();
  User&		currentUser();
  int run(int, char**);
  void logUser(const std::string &username, const std::string &password, const std::string &ip);
  void signup(const std::string &username, const std::string &password, const std::string &verify, const std::string &avatar);
};

extern PTUser g_PTUser;
#endif
