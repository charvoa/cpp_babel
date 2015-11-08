//
// IProtocolHelper.hh for IProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 27 02:25:39 2015 Antoine Garcia
// Last update Sun Nov  1 05:07:52 2015 Antoine Garcia
//

#ifndef IProtocolHelper_HH_
# define IProtocolHelper_HH_

#include <QByteArray>
typedef enum ProtocolType
  {
    HANDSHAKE = 1,
    SUCCESS = 2,
    ERROR_PROTO = 3,
    SIGNUP = 4,
    SIGNIN = 5,
    CALL_REQUEST = 6,
    HANGUP = 7,
    SEND_TEXT = 8,
    PONG = 9,
    ACCEPT_CALL = 10,
    DECLINE_CALL = 11,
    ADD_CONTACT = 12,
    ACCEPT_INVITATION = 13,
    DECLINE_INVITATION = 14,
    MODIFY_STATUS = 15,
    MODIFY_LOGIN = 16,
    MODIFY_LOCATION = 17,
    MUTE = 20,
    ADD_PARTICIPANT_TO_CALL = 21,
    ADD_TO_FAVORITES = 22,
    REMOVE_FROM_FAVORITE = 23,
    ADD_NICKNAME = 24,
    REMOVE_CONTACT = 25,
    MODIFY_PROFIL_PICTURE = 26,
    SEND_FILE = 30,
    LISTEN_TO_MAIL = 31,
  }	ProtocolType;

class	IProtocolHelper
{

public:
  virtual ~IProtocolHelper() = 0;
  virtual QByteArray &createRequest(ProtocolType type) = 0;
};

#endif
