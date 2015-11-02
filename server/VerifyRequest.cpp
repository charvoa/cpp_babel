//
// VerifyRequest.cpp for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 22 21:48:58 2015 Nicolas Girardot
// Last update Mon Nov  2 16:48:49 2015 Nicolas Girardot
//

#include "VerifyRequest.hh"

#define	HEADER_SIZE 7

VerifyRequest::VerifyRequest(const std::string &request)
{
  verify(request);
}

VerifyRequest::~VerifyRequest()
{

}

void	VerifyRequest::verify(const std::string &request) const
{
  std::bitset<8> first8(request.at(5));
  std::bitset<8> second8(request.at(6));
  std::bitset<16> whole(first8.to_string() + second8.to_string());

  if ((request.length() - HEADER_SIZE) == whole.to_ulong())
    {
      DataFromClient *manag = new DataFromClient(request);
      (void)manag;
    }
  else
    {

    }
}
