//
// Account.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 29 15:28:27 2015 Nicolas Girardot
// Last update Mon Nov  2 18:24:35 2015 Nicolas Charvoz
//

#include "Account.hh"
#include <boost/lexical_cast.hpp>

Account::Account(std::string login, std::string passwd, short profilePicture)
{
  _login = login;
  _passwd = passwd;
  _state = Account::DISCONNECTED;
  _profilePicture = profilePicture;
}

Account::~Account()
{

}

void							Account::setNickname(std::string &id, std::string &newNickName)
{
  this->_nicknames.insert(std::make_pair(id, newNickName));;
}

void							Account::setProfilePicture(short pp)
{
  this->_profilePicture = pp;
}

void							Account::setSocket(boost::shared_ptr<TCPConnection> socket)
{
  this->_socket = socket;
}

std::string			        		&Account::getLogin()
{
  return _login;
}

short			        		Account::getProfilePictureID()
{
  return _profilePicture;
}

std::string		         			&Account::getLocation()
{
  return _location;
}

std::string		         			&Account::getPasswd()
{
  return _passwd;
}

boost::shared_ptr<TCPConnection>  &Account::getSocket()
{
  return _socket;
}

std::vector<Account*>				&Account::getContactList()
{
  return _contactList;
}

std::map<std::string,std::string>				&Account::getNicknames()
{
  return _nicknames;
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
  if (this->getLogin() == bis.getLogin())
    return true;
  return false;
}

bool   			Account::isAlreadyAContactOf(Account *contactAdded)
{
  if (_contactList.empty())
    return false;
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
  if (_contactList.empty())
    return false;
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
  if (_favoriteList.empty())
    return false;
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


bool Account::isIDFavorited(std::string ID)
{
  for (std::vector<Account*>::iterator it = _favoriteList.begin(); it != _favoriteList.end(); ++it)
    {
      if ((*it)->getID() == ID)
        return true;
    }
  return false;
}

std::string &Account::getNicknameIfExisting(Account *account)
{
  for (std::map<std::string, std::string>::iterator it = _nicknames.begin(); it != _nicknames.end(); ++it)
    {
      if ((*it).first == account->getID())
        return (*it).second;
    }
  return account->getLogin();
}

std::vector<std::string> Account::getFormatedContactList()
{
  std::vector<std::string> contactsInformations;

  contactsInformations.push_back(this->getID());
  std::vector<char> std;
  std.push_back(_contactList.size());
  std::string str(std.begin(), std.end());
  contactsInformations.push_back(str);

  if (_contactList.empty())
    return contactsInformations;
  for (std::vector<Account*>::iterator it = _contactList.begin(); it != _contactList.end(); ++it)
    {
      contactsInformations.push_back((*it)->getID());
      contactsInformations.push_back(this->getNicknameIfExisting((*it)));
      contactsInformations.push_back((*it)->getLocation());
      contactsInformations.push_back(std::to_string(boost::lexical_cast<char>(((*it)->getState()))));
      contactsInformations.push_back(std::to_string(boost::lexical_cast<char>(((*it)->getProfilePictureID()))));
      contactsInformations.push_back(std::to_string(boost::lexical_cast<char>((this->isIDFavorited((*it)->getID())))));
    }
  return contactsInformations;
}

void			Account::setLogin(std::string &login)
{
  _login = login;
}

void			Account::setLocation(std::string location)
{
  _location = location;
}

void			Account::setID(const std::string &id)
{
  _id = id;
}

void       Account::generateRandomID(size_t length)
{
  std::srand(std::time(0));
  int random = std::rand();
  auto randchar = [random]() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t maxIndex = (sizeof(charset) - 1);
        return charset[random % maxIndex];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    this->setID(str);
}
