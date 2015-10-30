//
// Account.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 28 10:45:59 2015 Nicolas Girardot
// Last update Wed Oct 28 14:52:21 2015 Nicolas Girardot
//

#ifndef _ACCOUNT_HH
# define _ACCOUNT_HH

#include <string>
#include <pair>
#include "TCPConnection.hh"

class		        Account
{
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

  void			setLogin(std::string login);
  void			setState(Account::state state);
  void			setLocation(std::string location);

  std::string			        		&getUsername();
  std::string		         			&getLocation();
  std::string		         			&getPasswd();
  std::vector<Account*>				&getContactList();
  Account::state		      		getState();
  std::string   		      		getID();
  bool                        removeContact(std::string ID);

private:

  TCPConnection::pointer			_socket;
  std::string			        		_username;
  std::string					        _passwd;
  Account::state       				_state;
  std::string					        _location;
  std::vector<std::pair<Account*:std::string>>	_nicknames;
  std::vector<Account*>				_contactsList;
  std::vector<Account*>				_favoritesList;
  const std::string           _id;
  TCPConnection               _socket;
};

#endif /* !ACCOUNT_HH_ */
