//
// Contact.cpp for  in /home/nicolaschr/rendu/cpp_babel/app/Contact
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun Nov  1 16:01:10 2015 Nicolas Charvoz
// Last update Sun Nov  8 19:32:50 2015 Nicolas Charvoz
//

#include "Contact.hh"
#include <cstdlib>
#include <ctime>

Contact::Contact(const std::string &username, const std::string &location,
		 int status, int id, int fav) : _username(username),
						      _location(location),
						      _status(status),
						      _idPic(id),
						      _fav(fav)
{
  int random_variable = std::rand() % 8 + 1;
  _idPic = random_variable;
  std::cout << "Contact created" << std::endl;
}

Contact::~Contact() {}

const Contact &Contact::getContact() const
{
  return *this;
}

Contact &Contact::getContact()
{
  return *this;
}

std::string Contact::getName() const
{
  return _username;
}

std::string Contact::getLocation() const
{
  return _location;
}

int Contact::getStatus() const
{
  return _status;
}

int Contact::getPic() const
{
  return _idPic;
}

bool Contact::isFav() const
{
  if (_fav == 1)
    return true;
  return false;
}
