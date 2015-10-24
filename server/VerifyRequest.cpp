//
// VerifyRequest.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 22 21:48:58 2015 Nicolas Girardot
// Last update Thu Oct 22 22:13:04 2015 Nicolas Girardot
//

#include "VerifyRequest.hh"

#define HEADER_SIZE = 3;

VerifyRequest(const std::string &request)
{
  bitset<8> first8(request.at(1));
  bitset<8> second8(request.at(2));

  bitset<16> whole(first8.to_string() + second8.to_string());
  if ((request.length - HEADER_SIZE) == whole.to_ulong())
    {
      std::cout << "OK" << std::endl;
    }
  else
    {
      std::cout << "not OK" << std::endl;
    }
}
