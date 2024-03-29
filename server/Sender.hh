//
// Sender.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:21:39 2015 Serge Heitzler
// Last update Sun Nov  1 16:45:48 2015 Serge Heitzler
//

#ifndef _SENDER_HH
# define _SENDER_HH

#include <string>
#include "Response.hh"
#include "Common/TCPConnection.hh"

class			Sender
{

  Sender();
  ~Sender();

  // Abstraction Boost Asio Methods

public:
  static void		       	send(Response *response);
  static void		       	specialSending(Response *response);

private:


};

#endif /* !SENDER_HH_ */
