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

std::string			        		Account::getUsername()
{
  return _username;
}

std::string		         			Account::getLocation()
{
  return _location;
}

std::string		         			Account::getPasswd()
{
  return _passwd;
}

std::vector<Account*>				Account::getContactList()
{

}

Account::state		      		Account::getState()
{
  return _state;
}

std::string   		      		Account::getID()
{
  return _id;
}

Account                     &Account::getContactByID(std::string ID)
{
  for (std::vector::iterator it = _contactsList.begin(); it != _contactsList.end(); ++it)
    {
      if (it->getID() == ID)
        return _contactsList.at(std::distance(_contactsList.begin(), it));
    }
  return NULL;
}

std::vector::iterator        Account::getContactIteratorByIDInVector(std::string ID, std::vector<Account*> _vector)
{
  for (std::vector::iterator it = _vector.begin(); it != _vector.end(); ++it)
    {
      if (it->getID() == ID)
        return it;
    }
  return NULL;
}

// Faire overload operator == pour Account
bool                        Account::isAlreadyAContactOf(Account &contactAdded)
{
  for (std::vector::iterator it = _contactsList.begin(); it != _contactsList.end(); ++it)
    {
      if (it == contactAdded)
        return true;
    }
  return false;
}

bool                        Account::addContact(Account &contactAdded)
{
  if !this.isAlreadyAContactOf(contactAdded)
    {
      _contactsList.push_back(contactAdded);
      return true;
    }
  return false;
}

bool                        Account::removeContact(std::string ID)
{
  _contactsList.erase(this.getContactIteratorByIDInVector(ID, _contactsList));
  _favoritesList.erase(this.getContactIteratorByIDInVector(ID, _favoritesList));
  return true;
}

bool                        Account::addToFavorites(Account &favorited)
{
  _favoritesList.push_back(favorited);
  return true;
}

bool                        Account::removeFromFavorites(std::string ID)
{
  _favoritesList.erase(this.getContactIteratorByIDInVector(ID, _favoritesList));
  return true;
}
