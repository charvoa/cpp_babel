//
// main.cpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 20:40:02 2015 Nicolas Girardot
// Last update Sun Nov  8 21:20:04 2015 Nicolas Girardot
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
  Server g_Server;
  return 0;
}
