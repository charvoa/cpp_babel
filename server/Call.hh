#ifndef CALL_HH_
# define CALL_HH_

#include <chrono>
#include "PTObject.hh"

class				Call : PTObject
{

  typedef enum			status
    {
      MISSED,
      ANSWERED
    }

  typedef enum			restriction
    {
      OWNER,
      ALL
    };

  Call();
  ~Call();
    
  void				addParticipant(Account &participant);

private:

  std::chrono::duration		_duration;
  std::vector<Account*>		_participants;
  Call::restriction    		_restriction;
  Call::status			_status;
  Conversation&			_conversation;
  Account&			_owner; // Client's objectID

}
