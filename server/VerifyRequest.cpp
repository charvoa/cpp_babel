//
// VerifyRequest.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 22 21:48:58 2015 Nicolas Girardot
// Last update Sun Nov  1 15:07:51 2015 Nicolas Girardot
//

#include "VerifyRequest.hh"

#define	HEADER_SIZE 7

VerifyRequest::VerifyRequest(const std::string &request)
{
  std::cout << "VerifyRequest Constructor Begining" << std::endl;

  std::bitset<8> first8(request.at(5));
  std::bitset<8> second8(request.at(6));

  std::bitset<16> whole(first8.to_string() + second8.to_string());
  std::cout << "Request official size = " << whole.to_ulong() << " ; Request Non Official size = " << request.length() - HEADER_SIZE << std::endl;
  if ((request.length() - HEADER_SIZE) == whole.to_ulong())
    {
      std::cout << "OK" << std::endl;
      DataFromClient *manag = new DataFromClient(request);
      (void) manag;
    }
  else
    {
      std::cout << "not OK" << std::endl;
    }

  std::cout << "VerifyRequest Constructor End" << std::endl;
}

VerifyRequest::~VerifyRequest()
{

}
