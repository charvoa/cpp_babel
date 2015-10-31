//
// Account.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 29 15:28:27 2015 Nicolas Girardot
// Last update Sat Oct 31 17:46:37 2015 Nicolas Girardot
//

#include "Account.hh"

Account::Account(std::string login, std::string passwd, short profilePicture)
{
  _login = login;
  _passwd = passwd;
  _state = Account::CONNECTED;
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

std::vector<std::string> &Account::getFormatedContactList()
{
  std::vector<std::string> contactsInformations;

  contactsInformations.push_back(this->getID());
  contactsInformations.push_back(std::to_string(_contactList.size()));
  for (std::vector<Account*>::iterator it = _contactList.begin(); it != _contactList.end(); ++it)
    {
      contactsInformations.push_back((*it)->getID());
      contactsInformations.push_back(this->getNicknameIfExisting((*it)));
      contactsInformations.push_back((*it)->getLocation());
      contactsInformations.push_back(std::to_string((*it)->getState()));
      contactsInformations.push_back(std::to_string((*it)->getProfilePictureID()));
      contactsInformations.push_back(std::to_string(this->isIDFavorited((*it)->getID())));
    }
}

void			Account::setLogin(std::string &login)
{
  _login = login;
}

void			Account::setLocation(std::string location)
{
  _location = location;
}
