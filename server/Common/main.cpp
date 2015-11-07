//
// main.cpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 20:40:02 2015 Nicolas Girardot
// Last update Mon Nov  2 18:00:00 2015 Nicolas Girardot
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "Network.hpp"
#include "../Server.hh"

using boost::asio::ip::tcp;

int main()
{
  std::srand(std::time(NULL));
  std::cout << "COPILED SUCCCCESS" << std::endl;
  Server g_Server;
  return 0;
}
