#ifndef _ACCOUNT_HH
# define _ACCOUNT_HH

#include <string>
#include <pair>

class		        Account
{
  typedef enum		State
    {
      CONNECTED = 1,
      AWAY = 2,
      ONCALL = 3,
      DISCONNECTED = 4
    }			        State;

  Account(short clientVersion);
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
  short                       getClientVersion
  Socket	              			getSocket();
  bool                        removeContact(std::string &ID);

private:

  std::string			        		_username;
  std::string					        _passwd;
  Account::state       				_state;
  std::string					        _location;
  std::vector<std::pair<Account*:std::string>>	_nicknames;
  std::vector<Account*>				_contactsList;
  std::vector<Account*>				_favoritesList;

  std::string                 _id;

  Socket										_socket;

  short						_clientVersion;

};

#endif /* !ACCOUNT_HH_ */
