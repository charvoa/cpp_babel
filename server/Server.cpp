#include "Server.hh"

Server::Server()
{

}

Server::~Server()
{

}

bool      Server::isUsernameExisting(std::string &username)
{
  for (std::vector::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if (it->getLogin() == username)
        return true;
    }
  return false;
}

bool      Server::isPasswdCorrectForAccount(std::string &username, std::string &passwd)
{
  for (std::vector::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if (it->getLogin() == username && it->getPasswd() == passwd)
        return true;
    }
  return false;
}

bool      Server::addAccount(std::string &login, std::string &passwd, short profilePicture)
{
  _allAccounts.push_back(new Account(login, passwd, profilePicture));
}

Account   &Server::getAccountByID(std::string &ID)
{
  for (std::vector::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if (it->getID() == ID)
        return _allAccounts.at(std::distance(_allAccounts.begin(), it));
    }
  return NULL;
}

Account   &Server::getAccountIteratorByID(std::string &ID)
{
  for (std::vector::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if (it->getID() == ID)
        return it;
    }
  return NULL;
}

Account   &Server::getAccountByUsername(std::string &username)
{
  for (std::vector::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if (it->getUsername() == username)
        return it;
    }
  return NULL;
}

Client   &Server::getClientBySocket(Socket &socket)
{
  for (std::vector::iterator it = _allClients.begin(); it != _allClients.end(); ++it)
    {
      if (it->getSocket() == socket)
        return _allClients.at(std::distance(_allClients.begin(), it));
    }
  return NULL;
}
