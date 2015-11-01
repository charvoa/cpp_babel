//
// Contact.cpp for  in /home/nicolaschr/rendu/cpp_babel/app/Contact
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Nov  1 16:01:10 2015 Nicolas Charvoz
// Last update Sun Nov  1 16:20:11 2015 Nicolas Charvoz
//

#include "Contact.hh"

Contact::Contact(std::string username, std::string ip, std::string location,
		 int status, int id, int fav) : _username(username), _ip(ip),
						      _location(location),
						      _status(status),
						      _idPic(id),
						      _fav(fav)
{
  std::cout << "Contact created" << std::endl;
}
