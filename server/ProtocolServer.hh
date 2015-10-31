//
// ProtocolServer.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:51:14 2015 Serge Heitzler
// Last update Sat Oct 31 22:09:05 2015 Serge Heitzler
//

#ifndef _PROTOCOLSERVER_HH
# define _PROTOCOLSERVER_HH

#include <string>
#include "DataToClient.hh"

class		        ProtocolServer : public AProtocol
{

  ProtocolServer();
  ~ProtocolServer();

private:

  static bool	ping(DataToClient &toData);
  static bool	contactList(DataToClient &toData);
  static bool	contactInfo(DataToClient &toData);
  static bool	contactRequest(DataToClient &toData);
  static bool	callRequest(DataToClient &toData);
  static bool	sendText(DataToClient &toData);
  static bool	hangedUp(DataToClient &toData);
  static bool	sendFile(DataToClient &toData);

};

#endif /* !PROTOCOLSERVER_HH_ */
