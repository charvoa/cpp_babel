//
// Account.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 29 15:28:27 2015 Nicolas Girardot
// Last update Sat Oct 31 14:14:30 2015 Nicolas Girardot
//

#include "Account.hh"

Account::Account(std::string username, std::string passwd, short profilePicture)
{
  _username = username;
  _passwd = passwd;
  _state = Account::CONNECTED;
  _profilePicture = profilePicture;
}

Account::~Account()
{

}

void							Account::setNickname(std::string &id, std::string &newNickName)
{
  this->_nicknames.push_back(std::make_pair(id, newNickName));;
}

void							Account::setProfilePicture(short pp)
{
  this->_profilePicture = pp;
}

std::string			        		&Account::getUsername()
{
  return _username;
}

std::string		         			&Account::getLocation()
{
  return _location;
}

std::string		         			&Account::getPasswd()
{
  return _passwd;
}

std::vector<Account*>				&Account::getContactList()
{
  return _contactList;
}

Account::State		      		Account::getState()
{
  return _state;
}

std::string   		      		Account::getID()
{
  return _id;
}

Account                     *Account::getContactByID(std::string &ID)
{
  for (std::vector<Account*>::iterator it = _contactList.begin(); it != _contactList.end(); ++it)
    {
      if ((*it)->getID() == ID)
        return _contactList.at(std::distance(_contactList.begin(), it));
    }
  return NULL;
}

bool				Account::operator==(Account &bis)
{
  if (this->getUsername() == bis.getUsername())
    return true;
  return false;
}

bool   			Account::isAlreadyAContactOf(Account *contactAdded)
{
  for (std::vector<Account*>::iterator it = _contactList.begin(); it != _contactList.end(); ++it)
    {
      if ((*it) == contactAdded)
        return true;
    }
  return false;
}

bool				Account::addContact(Account *contactAdded)
{
  if (!(this->isAlreadyAContactOf(contactAdded)))
    {
      _contactList.push_back(contactAdded);
      return true;
    }
  return false;
}

bool				Account::removeContact(std::string &ID)
{
  for (std::vector<Account*>::iterator it = _contactList.begin(); it != _contactList.end(); ++it)
    {
      if ((*it)->getID() == ID)
	{
	  delete * it;
	  it = _favoriteList.erase(it);
	}
    }
  return true;
  removeFromFavorite(ID);
  return true;
}

bool                        Account::addToFavorite(Account *favorited)
{
  _favoriteList.push_back(favorited);
  return true;
}

bool                        Account::removeFromFavorite(std::string &ID)
{
  for (std::vector<Account*>::iterator it = _favoriteList.begin(); it != _favoriteList.end(); ++it)
    {
      if ((*it)->getID() == ID)
	{
	  delete * it;
	  it = _favoriteList.erase(it);
	}
    }
  return true;
}
