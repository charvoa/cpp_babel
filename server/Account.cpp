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

Socket	              			Account::getSocket()
{
  return _socket;
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

std::vector::iterator        Account::getContactIteratorByID(std::string ID)
{
  for (std::vector::iterator it = _contactsList.begin(); it != _contactsList.end(); ++it)
    {
      if (it->getID() == ID)
        return it;
    }
  return NULL;
}

bool                        Account::removeContact(std::string ID)
{
  _contactsList.erase(this.getContactIteratorByID(ID));
  return true;
}
