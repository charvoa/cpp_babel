#ifndef _SENDER_HH
# define _SENDER_HH

#include <string>

class			Sender
{

  Sender(Response &response);
  ~Sender();

  static void	       	send();

private:


};

#endif /* !SENDER_HH_ */
