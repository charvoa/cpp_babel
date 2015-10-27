//
// Contact.hh for Contact in /home/antoinegarcia/rendu/cpp_babel/app/Contact
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 26 07:24:39 2015 Antoine Garcia
// Last update Mon Oct 26 07:41:04 2015 Antoine Garcia
//

#ifndef CONTACT_HH_
# define CONTACT_HH_

#include <string>
class	Contact
{
  std::string	username;
  std::string	ip;
  std::string	location;
public:
  Contact();
  ~Contact();
};

#endif
