#ifndef _RESPONSE_HH
# define _RESPONSE_HH

#include <string>

#define CHAR_SEPARATOR ";"

class		        Response
{

  Response(AProtocol::CommunicationType answerType, std::vector<std::string> data);
  ~Response();

private:

  short                 _sizeData = 0;
  std::string           _response;
};

#endif /* !RESPONSE_HH_ */
