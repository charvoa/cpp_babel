//
// Sender.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:40:20 2015 Serge Heitzler
// Last update Sat Nov  7 17:53:41 2015 Nicolas Girardot
//

#include "Sender.hh"

Sender::Sender()
{
  std::cout << "Passing in Sender" << std::endl;
}

Sender::~Sender()
{

}

void Sender::send(Response *response)
{
  response->getClient()->getSocket()->asyncWrite(response->getResponse());
}

void Sender::specialSending(Response *response)
{

  response->getSocket()->asyncWrite(response->getResponse());
}
