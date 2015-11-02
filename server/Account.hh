//
// Account.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Oct 28 10:45:59 2015 Nicolas Girardot
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

  Account(std::string login, std::string passwd, short profilePicture);
  ~Account();

  void						setLogin(std::string &login);
  void						setState(Account::State state);
  void						setLocation(std::string location);
  void						setNickname(std::string &id, std::string &nickname);
  void						setProfilePicture(short);
  void					  setSocket(boost::shared_ptr<TCPConnection> socket);
  std::string			        	&getLogin();
  std::string		         		&getLocation();
  std::string		         		&getPasswd();
  boost::shared_ptr<TCPConnection>  &getSocket();
  std::vector<Account*>				&getContactList();
  std::map<std::string,std::string>	&getNicknames();
  Account					*getContactByID(std::string &);
  Account::State		      		getState();
  bool						isAlreadyAContactOf(Account *);
  bool            isIDFavorited(std::string ID);
  short			        		getProfilePictureID();
  std::string &getNicknameIfExisting(Account *account);
  bool						addContact(Account *);
  std::string   		      		getID();
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
  short						_profilePicture;
  std::string					        _location;
  std::map<std::string,std::string>	_nicknames;
  std::vector<Account*>				_contactList;
  std::vector<Account*>				_favoriteList;
  std::string           _id;
};

#endif /* !ACCOUNT_HH_ */
