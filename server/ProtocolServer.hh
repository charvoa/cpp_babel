#ifndef _PROTOCOLSERVER_HH
# define _PROTOCOLSERVER_HH

#include <string>
#include "DataToClient.hh"

class		        ProtocolServer : public AProtocol
{

  ProtocolServer();
  ~ProtocolServer();

private:

  bool	ping(Server &server, DataToClient &toData);
  bool	contactList(Server &server, DataToClient &toData);
  bool	contactInfo(Server &server, DataToClient &toData);
  bool	contactRequest(Server &server, DataToClient &toData);
  bool	callRequest(Server &server, DataToClient &toData);
  bool	sendText(Server &server, DataToClient &toData);
  bool	hangedUp(Server &server, DataToClient &toData);
  bool	sendFile(Server &server, DataToClient &toData);

};

#endif /* !PROTOCOLSERVER_HH_ */
