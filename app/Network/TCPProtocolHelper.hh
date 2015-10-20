//
// TCPProtolHelper.hh for TCPProtolHelper.hh in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 13:34:10 2015 Antoine Garcia
// Last update Tue Oct 20 07:06:07 2015 Antoine Garcia
//

#ifndef TCPProtocolHelper_HH_
# define TCPProtocolHelper_HH_

#include <string>
#include <cstdlib>

typedef enum TCPProtocolHeader
  {
    SIGN_UP,
    SIGN_IN,
    CALL,
    MUTE,
    HANG_UP,
    SEND_TEXT,
    SEND_FILE,
    ADD_PARTICIPANT,
    ADD_CONTACT,
    GET_CONTACT,
    REMOVE_CONTACT,
    MODIFY_PROFIL_PICTURE,
    MODIFY_STATUS,
    MODIFY_LOGIN,
    MODIFY_LOCATION,
    ADD_NICKNAME,
    LISTEN_TO_MAIL

  }TCPProtocolHeader;

class	TCPProtolHelper
{
  std::string	_data;
public:
  TCPProtolHelper(const std::string &data = NULL);
  ~TCPProtolHelper();
  const	writeHead(TCPProtocolHelper type);
  char		     readHeader(const std::string &);
  const std::string	&getData();
};

#endif
