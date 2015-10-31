//
// Sender.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:21:39 2015 Serge Heitzler
// Last update Sat Oct 31 16:22:04 2015 Serge Heitzler
//

#ifndef _SENDER_HH
# define _SENDER_HH

#include <string>

class			Sender
{

  Sender(AResponse &response);
  ~Sender();

  // Abstraction Boost Asio Methods

  static void		       	send();

private:


};

#endif /* !SENDER_HH_ */
