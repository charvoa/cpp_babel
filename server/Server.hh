#ifndef SERVER_HH_
# define SERVER_HH_

#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

class				Server
{

  Server();
  ~Server();

  std::vector<Account*>		_allAccounts;
  std::vector<Call*>		_allCalls;
  
  
  boost::posix_time::ptime     	_date;

};
