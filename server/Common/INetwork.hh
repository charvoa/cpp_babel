//
// INetwork.hh for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 20 15:40:25 2015 Nicolas Girardot
// Last update Wed Oct 28 21:36:48 2015 Nicolas Girardot
//

#ifndef INETWORK_HH_
# define INETWORK_HH_

# include <string>
# include <iostream>
class		INetwork
{
public:
  virtual ~INetwork() {};
  virtual void start() = 0;
  //  virtual void write(Socket &, const std::string &) = 0;
  virtual void read() = 0;
};

#endif
