//
// Sender.cpp for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:40:20 2015 Serge Heitzler
// Last update Sat Oct 31 16:40:24 2015 Serge Heitzler
//

Sender::Sender()
{

}

Sender::~Sender()
{

}

static void Sender::send(Response &response)
{
  response.(*_toClient)->getSocket()->asyncWrite(response._response);
}
