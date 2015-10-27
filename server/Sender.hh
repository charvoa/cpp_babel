#ifndef _SENDER_HH
# define _SENDER_HH

#include <string>

class			Sender
{

  Sender(AResponse &response);
  ~Sender();

  // Abstraction Boost Asio Methods

  void		       	send();

private:


};

#endif /* !SENDER_HH_ */
