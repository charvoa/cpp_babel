//
// PTUser.hh for  in /home/nicolaschr/rendu/cpp_babel/app/User
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov  2 13:57:49 2015 Nicolas Charvoz
// Last update Sun Nov  8 14:42:05 2015 Nicolas Charvoz
//

#ifndef PTUSER_HH_
# define PTUSER_HH_

# include <cstdlib>
# include <iostream>
# include <list>
# include <string>
# include <regex>
# include <vector>
# include "../Contact/Contact.hh"
# include "../Network/NetworkServerHandler.hh"

# define PASSWORD_DONT_MATCH 3001
# define IP_PROBLEM 3002
# define NO_ERROR 1


class PTUser: public QObject
{
Q_OBJECT
private:
  class User
  {
    friend class PTUser;
    std::string _password;
    std::vector<Contact> _contact;
  protected:
    std::string _objectId;
    std::string _username;
  public:
    User();
    ~User();
    const std::string &getUsername() const;
    const std::string &getObjectId() const;
    const std::vector<Contact>& getContacts() const;
    void		addServerContact(QByteArray &array);
    void		addContact(const std::string &);
    const Contact &getContactFromName(const std::string&) const;
  };
  User	_currentUser;
  NetworkServerHandler server;
  std::string _ipServer;
  std::vector<std::string> _ipGroup;
  std::vector<std::string>	   _tabs;
private slots:
  void userConnected(int check);
signals:
  void canDisplayHome(int check);
  void	contactAdded();
public:
  PTUser();
  ~PTUser();
  void	contactIsAdd();
  User&		currentUser();
  NetworkServerHandler&	getServer();
  int run(int, char**);
  void logUser(const std::string &username,
	       const std::string &password, const std::string &ip);
  void signup(const std::string &username, const std::string &password,
	      const std::string &verify, const std::string &ip,
	      char avatar = '1');
  bool		isTabOpen(const std::string &) const;
  void		addToList(const std::string &);
  void		removeAtIndex(int index);
  void		setUsername(const std::string &);
private:
  bool checkIP() const;
  void getIPGroup(const std::string&);
};

extern PTUser g_PTUser;
#endif
