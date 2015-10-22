#ifndef _PROTOCOLCLIENT_HH
# define _PROTOCOLCLIENT_HH

#include <string>

class		        ProtocolServer : public AProcotol
{

  ProtocolServer();
  ~ProtocolServer();

private:

    bool	ping(/* determiner les args */);
    bool	contactList(/* determiner les args */);
    bool	contactInfo(/* determiner les args */);
    bool	contactRequest(/* determiner les args */);
    bool	pnw(/* determiner les args */);
    bool	ppo(/* determiner les args */);
    bool	plv(/* determiner les args */);
    bool	pin(/* determiner les args */);
    bool	pgt(/* determiner les args */);
    bool	pdi(/* determiner les args */);
    bool	pfk(/* determiner les args */);
    bool  seg(/* determiner les args */);
    bool	pbc(/* determiner les args */);
    bool	pie(/* determiner les args */);
    bool	pic(/* determiner les args */);
    bool  pdr(/* determiner les args */);
    bool	smg(/* determiner les args */);
    bool	eht(/* determiner les args */);
    bool	ebo(/* determiner les args */);
    bool	edi(/* determiner les args */);
    bool	pex(/* determiner les args */);
    bool	enw(/* determiner les args */);
    bool	tin(/* determiner les args */);
    bool	sgt(/* determiner les args */);


};

#endif /* !PROTOCOLCLIENT_HH_ */
