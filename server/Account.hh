//
// Account.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 28 10:45:59 2015 Nicolas Girardot
// Last update Sat Nov  7 16:58:47 2015 Serge Heitzler
// Last update Mon Nov  2 18:23:59 2015 Nicolas Charvoz
//

#ifndef _ACCOUNT_HH
# define _ACCOUNT_HH

#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <map>
#include "Common/TCPConnection.hh"

class			TCPConnection;

class		        Account
{
public:
  typedef enum		State
    {
      CONNECTED = 1,
      AWAY = 2,
      ONCALL = 3,
      OFFLINE = 4,
      DISCONNECTED = 5
    }			        State;

  Account(std::string login, std::string passwd, char profilePicture);
  ~Account();

  void						setLogin(std::string &login);
  void						setState(Account::State state);
  void						setLocation(std::string location);
  void						setNickname(std::string &id, std::string &nickname);
  void						setProfilePicture(short);
  std::vector<std::string>			getData() const;
  void					  setSocket(boost::shared_ptr<TCPConnection> socket);
  const std::string			        	&getLogin() const;
  const std::string		         		&getLocation() const;
  const std::string		         		&getPasswd() const;
  const boost::shared_ptr<TCPConnection>		&getSocket() const;
  const std::vector<Account*>				&getContactList() const;
  const std::map<std::string,std::string>	&getNicknames() const;
  Account					*getContactByID(std::string &);
  Account::State		      		getState() const;
  bool						isAlreadyAContactOf(Account *);
  bool            isIDFavorited(std::string ID);
  short			        		getProfilePictureID() const;
  const std::string					&getNicknameIfExisting(Account *account);
  bool						addContact(Account *);
  const std::string   		      		&getID() const;
  bool						removeContact(std::string &ID);
  bool						addToFavorite(Account *);
  bool						removeFromFavorite(std::string &);
  std::vector<std::string>                        getFormatedContactList();
  void            generateRandomID(size_t length);
  bool						operator==(Account &);
  void			      setID(const std::string &id);

private:

  boost::shared_ptr<TCPConnection>			_socket;
  std::string			        		_login;
  std::string					        _passwd;
  Account::State       				_state;
  char						_profilePicture;
  std::string					        _location;
  std::map<std::string,std::string>	_nicknames;
  std::vector<Account*>				_contactList;
  std::vector<Account*>				_favoriteList;
  std::string           _id;
};

#endif /* !ACCOUNT_HH_ */
