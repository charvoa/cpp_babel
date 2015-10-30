//
// Server.hh for server in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Oct 30 12:07:00 2015 Nicolas Girardot
// Last update Fri Oct 30 12:21:28 2015 Nicolas Girardot
//

#ifndef _SERVER_HH_
# define _SERVER_HH_

#include <string>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Account.hh"

class				Server
{

  Server();
  ~Server();

  std::vector<Account*>		_allAccounts;
  //std::vector<Client*>		_allClients;
  //std::vector<Call*>		_allCalls;


  boost::posix_time::ptime     	_date;

public:
  bool	doesUsernameExist(std::string &);
  bool	isPasswdCorrectForAccount(std::string &, std::string &);
  void	addAccount(std::string &, std::string &, short);
  Account	*getAccountByID(std::string &);
  Account	*getAccountByUsername(std::string &);
};

#endif /* !SERVER_HH_ */
