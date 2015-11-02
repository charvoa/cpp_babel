//
// PTUser.hh for  in /home/nicolaschr/rendu/cpp_babel/app/User
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov  2 13:57:49 2015 Nicolas Charvoz
// Last update Mon Nov  2 17:36:01 2015 Nicolas Charvoz
//

#ifndef PTUSER_HH_
# define PTUSER_HH_

# include <cstdlib>
# include <iostream>
# include <list>
# include <string>
# include <regex>
# include "../Contact/Contact.hh"
# include "../Network/NetworkServerHandler.hh"

# define PASSWORD_DONT_MATCH 3001

class PTUser: public QObject
{
Q_OBJECT
private:
  void	contactIsAdd();
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
    void		addContact();
  };
  User	_currentUser;
  NetworkServerHandler server;
  std::string _ipServer;
private slots:
  void userConnected(int check);
signals:
  void canDisplayHome(int check);
  void	contactAdded();
public:
  PTUser();
  ~PTUser();
  User&		currentUser();
  int run(int, char**);
  void logUser(const std::string &username,
	       const std::string &password, const std::string &ip);
  void signup(const std::string &username, const std::string &password,
	      const std::string &verify, const std::string &ip,
	      char avatar = '1');
private:
  bool checkIP(std::string const&) const;

};

extern PTUser g_PTUser;
#endif
