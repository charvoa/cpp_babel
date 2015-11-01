//
// Contact.hh for Contact in /home/antoinegarcia/rendu/cpp_babel/app/Contact
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 26 07:24:39 2015 Antoine Garcia
// Last update Sun Nov  1 16:20:06 2015 Nicolas Charvoz
//

#ifndef CONTACT_HH_
# define CONTACT_HH_

# include <iostream>
# include <string>

class	Contact
{
  std::string	_username;
  std::string	_ip;
  std::string	_location;
  int		_status;
  int		_idPic;
  int		_fav;
public:
  Contact(std::string username, std::string ip, std::string location,
	  int status, int id, int fav = 0);
  ~Contact();
};

#endif
