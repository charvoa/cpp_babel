#ifndef _SERVER_HH_
# define _SERVER_HH_

#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

class				Server
{

  Server();
  ~Server();

  std::vector<Account*>		_allAccounts;
  std::vector<Client*>		_allClients;
  std::vector<Call*>		_allCalls;


  boost::posix_time::ptime     	_date;

};

#endif /* !SERVER_HH_ */
