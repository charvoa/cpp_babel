//
// PTUser.cpp for  in /home/nicolaschr/rendu/cpp_babel/app/User
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Oct 19 18:25:42 2015 Nicolas Charvoz
// Last update Sat Nov  7 07:58:57 2015 Antoine Garcia
//

#include "PTUser.hh"
#include "../../gui/MyApplication.hpp"
#include "../../gui/MainWidget.hh"
#include "../../gui/LoginWidget.hh"
#include <iostream>

PTUser g_PTUser;

PTUser::PTUser()
{
  std::cout << "PTUSER CREATED" << std::endl;
  connect(&server, SIGNAL(userConnected(int)), this, SLOT(userConnected(int)));
}

void	PTUser::userConnected(int check)
{
  std::cout << "SLOT IS CALLED" << std::endl;
  emit canDisplayHome(check);
}

PTUser::~PTUser()
{
  std::cout << "Destroy" << std::endl;
}

int PTUser::run(int ac, char **av)
{
  MyApplication app(ac, av);
  LoginWidget *login;

  login = new LoginWidget;

  QFile File2("./gui/stylesheetLogin.qss");
  File2.open(QFile::ReadOnly);
  QString StyleSheet2 = QLatin1String(File2.readAll());

  /* Applying it */
  login->setStyleSheet(StyleSheet2);

  /* Opening CSS file for Main Widget*/

  QFile File("./gui/stylesheet.qss");
  File.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(File.readAll());

  /* Applying it */
  app.setStyleSheet(StyleSheet);

  /* Show login window */
  login->setAttribute(Qt::WA_DeleteOnClose);
  login->show();

  return app.exec();
}

PTUser::User&	PTUser::currentUser()
{
  return (_currentUser);
}

void		PTUser::setUsername(const std::string &username)
{
  _currentUser._username = username;
}

void	PTUser::logUser(const std::string &username, const std::string &password, const std::string &ip)
{
  std::cout << "PROCESSING LOGIN USER..." << std::endl;

  this->getIPGroup(ip);
  if (!(this->checkIP()))
    {
      emit canDisplayHome(IP_PROBLEM);
    }
  else
    {
      server.type = 0;
      server.login = username;
      server.password = password;
      std::cout << "Starting a server on >> " << _ipGroup[0]
		<< ":" << _ipGroup[1] << std::endl;
      server.start(_ipGroup[0].c_str(), atoi(_ipGroup[1].c_str()));
    }
}

bool PTUser::checkIP() const
{
  if (_ipGroup.size() != 2)
    {
      std::cout << "Forgot the port" << std::endl;
      return false;
    }
  std::string stringToCheck(_ipGroup[0]);
  std::regex rgx("(\\d{1,3}(\\.\\d{1,3}){3})");

  if (std::regex_match(stringToCheck, rgx))
    return true;
  std::cout << "IP DONT MATCH" << std::endl;
  return false;
}

void PTUser::getIPGroup(const std::string &ip)
{
  std::string delimiter = ":";

  std::string s(ip);
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos)
    {
      token = s.substr(0, pos);
      std::cout << token << std::endl;;
      _ipGroup.push_back(token);
      s.erase(0, pos + delimiter.length());
    }
  std::cout << s << std::endl;
  _ipGroup.push_back(s);
}

void	PTUser::signup(const std::string &username, const std::string &password, const std::string &verify, const std::string &ip, char avatar)
{
  this->getIPGroup(ip);
  if (!(this->checkIP()))
    {
      emit canDisplayHome(IP_PROBLEM);
    }
  else if (password != verify)
    {
      emit canDisplayHome(PASSWORD_DONT_MATCH);
    }
  else
    {
      server.type = 1;
      server.login = username;
      server.password = password;
      std::cout << "Starting a server on >> " << _ipGroup[0]
		<< ":" << _ipGroup[1] << std::endl;
      server.start(_ipGroup[0].c_str(), atoi(_ipGroup[1].c_str()));
    }
}

bool	PTUser::isTabOpen(const std::string & user) const
{
  bool found = (std::find(_tabs.begin(), _tabs.end(), user) != _tabs.end());
  return (found);
}

void	PTUser::addToList(const std::string &user)
{
  _tabs.push_back(user);
}

void	PTUser::removeAtIndex(int index)
{
  _tabs.erase(_tabs.begin() + index);
}

void	PTUser::contactIsAdd()
{

  emit contactAdded();
}
//Nested Class User
PTUser::User::User()
{
  std::cout << "User Create" << std::endl;
}

PTUser::User::~User()
{
  std::cout << "Destroy User" << std::endl;
}

void	PTUser::User::addContact(const std::string &username)
{
  _server.addContact(username);
}

const std::string	&PTUser::User::getUsername() const
{
  return (_username);
}

const std::string	&PTUser::User::getObjectId() const
{
  return (_objectId);
}

const std::vector<Contact *>	&PTUser::User::getContacts() const
{
  return (_contact);
}
