#ifndef _CHAT_HH
# define _CHAT_HH

#include <string>
#include <pair>

class					Chat : PTObject
{

  Chat();
  ~Chat();
  
private:

  std::vector<Message*>			_messages;

};

#endif /* !CONVERSATION_HH_ */
