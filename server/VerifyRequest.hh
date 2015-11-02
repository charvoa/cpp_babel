//
// VerifyRequest.hh for babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu Oct 22 21:37:09 2015 Nicolas Girardot
// Last update Mon Nov  2 16:45:25 2015 Nicolas Girardot
//

#ifndef VERIFYREQUEST_HH_
# define VERIFYREQUEST_HH_

#include <string>
#include <bitset>
#include "DataFromClient.hh"

class VerifyRequest
{
public:
  VerifyRequest(const std::string &);
  ~VerifyRequest();
  void	verify(const std::string &request) const;
};

#endif
