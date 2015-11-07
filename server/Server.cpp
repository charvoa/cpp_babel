//
// Server.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 29 17:45:35 2015 Nicolas Girardot
// Last update Sat Nov  7 17:19:00 2015 Nicolas Girardot
//

#include "Server.hh"

Server g_Server;

Server::Server()
{
  _net = new Network();
  _net->start();
}

Server::~Server()
{

}

bool      Server::doesUsernameExist(std::string &username)
{
  if (_allAccounts.empty())
    return false;
  for (std::vector<Account *>::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if ((*it)->getLogin() == username)
        return true;
    }
  return false;
}

bool      Server::isPasswdCorrectForAccount(std::string &username, std::string &passwd)
{
  if (_allAccounts.empty())
    return false;
  for (std::vector<Account *>::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if ((*it)->getLogin() == username && (*it)->getPasswd() == passwd)
        return true;
    }
  return false;
}

void      Server::addAccount(std::string &login, std::string &passwd, short profilePicture)
{
  _allAccounts.push_back(new Account(login, passwd, profilePicture));
}

Account   *Server::getAccountByID(std::string &ID)
{
  for (std::vector<Account *>::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      if ((*it)->getID() == ID)
        return (*it);
    }
  return NULL;
}

Account   *Server::getAccountByUsername(std::string &username)
{
  for (std::vector<Account *>::iterator it = _allAccounts.begin(); it != _allAccounts.end(); ++it)
    {
      std::cout << ";:;:;:;;:;::; Get login = " << (*it)->getLogin() << " ;; User is " << username << std::endl;
      if ((*it)->getLogin() == username)
        return (*it);
    }
  return NULL;
}

Network	*Server::getNetwork() const
{
  return (static_cast<Network *>(_net));
}
