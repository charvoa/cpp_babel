//
// Sender.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:40:20 2015 Serge Heitzler
// Last update Sun Nov  1 16:46:36 2015 Serge Heitzler
//

#include "Sender.hh"

Sender::Sender()
{

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
  response->getSocket()->getSocket()->asyncWrite(response->getResponse());
}
