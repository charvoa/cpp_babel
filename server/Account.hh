#ifndef _ACCOUNT_HH
# define _ACCOUNT_HH

#include <string>
#include <pair>

class		        Account : PTObject
{
  typedef enum		state
    {
      CONNECTED,
      AWAY,
      ONCALL,
      DISCONNECTED
    }			state;

  Account();
  ~Account();

  void			setLogin(std::string login);
  void			setState(Account::state state);
  void			setLogin(std::string login);

  std::string					&getLogin();
  std::string					&getLocation();
  std::string					&getPasswd();
  std::vector<Account*>				&getContactList();
  Account::state				getState();
  int						getFd();

private:

  std::string					_login;
  std::string					_passwd;
  Account::state       				_state;
  std::string					_location;

  std::vector<std::pair<Account*:std::string>>	_nicknames;

  std::vector<Account*>				_contactsList;
  std::vector<Account*>				_favoritesList;
  // std::vector<Call*>				_callsHistory;
  // std::vector<Record*>				_records;
  // std::vector<Mail*>				_mails;

  Socket										_socket;

  int						_clientVersion;

};

#endif /* !ACCOUNT_HH_ */
