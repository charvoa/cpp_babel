#ifndef _PROTOCOLSERVER_HH
# define _PROTOCOLSERVER_HH

#include <string>
#include "DataToClient.hh"

class		        ProtocolServer : public AProtocol
{

  ProtocolServer();
  ~ProtocolServer();

private:

  bool	ping(Server &server, DataToClient &data);
  bool	contactList(Server &server, DataToClient &data);
  bool	contactInfo(Server &server, DataToClient &data);
  bool	contactRequest(Server &server, DataToClient &data);
  bool	callRequest(Server &server, DataToClient &data);
  bool	sendText(Server &server, DataToClient &data);
  bool	hangedUp(Server &server, DataToClient &data);
  bool	sendFile(Server &server, DataToClient &data);

};

#endif /* !PROTOCOLSERVER_HH_ */
