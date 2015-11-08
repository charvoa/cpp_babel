//
// Account.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 29 15:28:27 2015 Nicolas Girardot
// Last update Sun Nov  8 13:55:07 2015 Nicolas Girardot
//

#include "Account.hh"
#include <boost/lexical_cast.hpp>

Account::Account(std::string login, std::string passwd, char profilePicture)
{
  _login = login;
  _passwd = passwd;
  _state = Account::DISCONNECTED;
  _profilePicture = profilePicture;
  _location = "Nice";
}

Account::~Account()
{

}

std::vector<std::string>				Account::getData() const
{
  std::vector<std::string> data;
  data.push_back(_login);
  data.push_back(_location);
  data.push_back(std::to_string(_state));
  data.push_back(std::to_string(_profilePicture));
  return data;
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

const std::string			        		&Account::getLogin() const
{
  return _login;
}

short			        		Account::getProfilePictureID() const
{
  return _profilePicture;
}

const std::string		         			&Account::getLocation() const
{
  return _location;
}

const std::string		         			&Account::getPasswd() const
{
  return _passwd;
}

const boost::shared_ptr<TCPConnection>  &Account::getSocket() const
{
  return _socket;
}

const std::vector<Account*>				&Account::getContactList() const
{
  return _contactList;
}

const std::map<std::string,std::string>				&Account::getNicknames() const
{
  return _nicknames;
}

Account::State		      		Account::getState() const
{
  return _state;
}

const std::string   		      		&Account::getID() const
{
  std::cout << "ID IS " << _id;
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

const std::string &Account::getNicknameIfExisting(Account *account)
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
  std::cout << "STR IN GET FORMATED CONTACT LIST = " << std::endl;
  contactsInformations.push_back(str);


  if (_contactList.empty())
    return contactsInformations;
  std::cout << "TOTO" << std::endl;
  for (std::vector<Account*>::iterator it = _contactList.begin(); it != _contactList.end(); ++it)
    {
      if ((*it) == NULL)
	{
	  std::cout << "NILL WTF" << std::endl;
	}
      else
	{
	  contactsInformations.push_back((*it)->getID());
	  std::cout << "-2" << std::endl;
	  contactsInformations.push_back(this->getNicknameIfExisting((*it)));
	  std::cout << "-1" << std::endl;
	  contactsInformations.push_back((*it)->getLocation());
	  std::cout << "0" << std::endl;
	  contactsInformations.push_back(std::to_string(static_cast<char>(((*it)->getState()))));
	  std::cout << "1" << std::endl;
	  contactsInformations.push_back(std::to_string(static_cast<char>(((*it)->getProfilePictureID()))));
	  std::cout << "2" << std::endl;
	  contactsInformations.push_back(std::to_string(static_cast<char>((this->isIDFavorited((*it)->getID())))));
	  std::cout << "CACA BITE" << std::endl;
	}
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
