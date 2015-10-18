//
// main.cpp for babel in /home/nicolas/rendu/cpp_babel/server/Unix
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 13 20:40:02 2015 Nicolas Girardot
// Last update Sun Oct 18 13:16:06 2015 Nicolas Girardot
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "TCPServer.hpp"
#include "TCPConnection.hpp"

using boost::asio::ip::tcp;

int main()
{
  try
    {
      boost::asio::io_service io_service;
      TCPServer server(io_service);
      io_service.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }

  return 0;
}
