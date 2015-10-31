//
// Account.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 28 10:45:59 2015 Nicolas Girardot
// Last update Sat Oct 31 11:21:02 2015 Nicolas Girardot
//

#ifndef _ACCOUNT_HH
# define _ACCOUNT_HH

#include <string>
#include <utility>
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

  Account(std::string username, std::string passwd, short profilePicture);
  ~Account();

  void						setLogin(std::string login);
  void						setState(Account::State state);
  void						setLocation(std::string location);

  std::string			        	&getUsername();
  std::string		         		&getLocation();
  std::string		         		&getPasswd();
  std::vector<Account*>				&getContactList();
  Account					*getContactByID(std::string &);
  Account::State		      		getState();
  bool						isAlreadyAContactOf(Account &);
  bool						addContact(Account &);
  std::string   		      		getID();
  bool						removeContact(std::string &ID);
  bool						addToFavorite(Account &);
  bool						removeFromFavorite(std::string &);
  bool						operator==(Account &);

private:

  boost::shared_ptr<TCPConnection>			_socket;
  std::string			        		_username;
  std::string					        _passwd;
  Account::State       				_state;
  short						_profilePicture;
  std::string					        _location;
  std::vector<std::pair<Account*,std::string> >	_nicknames;
  std::vector<Account*>				_contactList;
  std::vector<Account*>				_favoriteList;
  const std::string           _id;
};

#endif /* !ACCOUNT_HH_ */
