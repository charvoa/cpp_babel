#ifndef _SENDER_HH
# define _SENDER_HH

#include <string>

class			Sender
{

  Sender();
  ~Sender();

  static void	       	success();
  static void	       	error();
  static void	       	contactList(std::vector<std::string>);
  static void	       	contactInfo(Account &Account);

private:


};

#endif /* !ACCOUNT_HH_ */
