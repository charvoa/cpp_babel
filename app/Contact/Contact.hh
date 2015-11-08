//
// Contact.hh for Contact in /home/antoinegarcia/rendu/cpp_babel/app/Contact
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 26 07:24:39 2015 Antoine Garcia
// Last update Sun Nov  8 03:28:59 2015 Antoine Garcia
//

#ifndef CONTACT_HH_
# define CONTACT_HH_

# include <iostream>
# include <string>

class	Contact
{
  std::string	_username;
  std::string	_location;
  int		_status;
  int		_idPic;
  int		_fav;
public:
  Contact(const std::string &username, const std::string &location,
	  int status, int id, int fav = 0);
  ~Contact();
  const Contact &getContact() const;
  Contact &getContact();
  std::string getName() const;
  std::string getLocation() const;
  int getStatus() const;
  int getPic() const;
  bool isFav() const;

};

#endif
