#ifndef _MESSAGE_HH_
# define _MESSAGE_HH_

#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>

class				Message
{

  Message();
  ~Message();

private:

  std::string			_text;
  boost::posix_time::ptime     	_date;
  Account&			_sender;
  Account&			_receiver;

};

#endif /* !Message_HH_ */
