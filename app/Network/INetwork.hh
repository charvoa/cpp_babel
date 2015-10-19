//
// INetwork.hh for INetwork in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 07:59:42 2015 Antoine Garcia
// Last update Mon Oct 19 08:05:20 2015 Antoine Garcia
//

#ifndef INETWORK_HH_
# define INetwork_HH_

class	INetwork
{
public:
  virtual ~INetwork(){}
  virtual void start(const std::string &host, unsigned int port) = 0;
}

#endif
