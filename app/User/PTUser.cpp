//
// PTUser.cpp for  in /home/nicolaschr/rendu/cpp_babel/app/User
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Oct 19 18:25:42 2015 Nicolas Charvoz
// Last update Mon Nov  2 17:35:26 2015 Nicolas Charvoz
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

void	PTUser::logUser(const std::string &username, const std::string &password, const std::string &ip)
{
  (void)ip;
  std::cout << "PROCESSING LOGIN USER..." << std::endl;
  server.type = 0;
  server.login = username;
  server.password = password;
  server.start("localhost", 4040);
}

bool PTUser::checkIP(std::string const &stringToCheck) const
{
  std::regex rgx("(\\d{1,3}(\\.\\d{1,3}){3})");

  if (std::regex_match(stringToCheck, rgx))
    return true;
  return false;
}

void	PTUser::signup(const std::string &username, const std::string &password, const std::string &verify, const std::string &ip, char avatar)
{
  std::string delimiter = ":";

  std::string s(ip);
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
  }
  std::cout << s << std::endl;

  if (password != verify)
    emit canDisplayHome(PASSWORD_DONT_MATCH);
  else
    {
      server.type = 1;
      server.login = username;
      server.password = password;
      server.start("localhost", 4040);
    }
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

void	PTUser::User::addContact()
{
  g_PTUser.contactIsAdd();
}

const std::string	&PTUser::User::getUsername() const
{
  return (_username);
}

const std::string	&PTUser::User::getObjectId() const
{
  return (_objectId);
}

const std::list<Contact *>	&PTUser::User::getContacts() const
{
  return (_contact);
}
