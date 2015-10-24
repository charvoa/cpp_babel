#ifndef _ARESPONSE_HH
# define _ARESPONSE_HH

#include <string>

class		        AResponse
{

  AResponse();
  ~AResponse();

  DataToClient          _data;

private:

  bool                  convertToBinaryForm();


};

#endif /* !ARESPONSE_HH_ */
