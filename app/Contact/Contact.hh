//
// Contact.hh for Contact in /home/antoinegarcia/rendu/cpp_babel/app/Contact
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 26 07:24:39 2015 Antoine Garcia
// Last update Mon Nov  2 10:49:29 2015 Nicolas Charvoz
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
  const Contact &getContact() const;
  Contact &getContact();
  std::string getName() const;
  std::string getIP() const;
  std::string getLocation() const;
  int getStatus() const;
  int getPic() const;
  bool isFav() const;

};

#endif
