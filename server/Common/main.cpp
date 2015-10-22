//
// main.cpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 20:40:02 2015 Nicolas Girardot
// Last update Wed Oct 21 15:14:09 2015 Nicolas Girardot
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "Network.hpp"

using boost::asio::ip::tcp;

int main()
{
  Network net;
  net.start();
  return 0;
}
