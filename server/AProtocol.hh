#ifndef _APROTOCOL_HH
# define _APROTOCOL_HH

#include <string>
#include <vector>
#include <distance>
#include "Server.hh"
#include "AData.hh"

class		        AProcotol
{

  typedef enum CommunicationType {
    C_HANDSHAKE = 1,
    C_SUCCESS = 2,
    C_ERROR = 3,
    C_SIGNUP = 4,
    C_SIGNIN = 5,
    C_CALL_REQUEST = 6,
    C_HANGUP = 7,
    C_SEND_TEXT = 8,
    C_PONG = 9,
    C_ACCEPT_CALL = 10,
    C_DECLINE_CALL = 11,
    C_ADD_CONTACT = 12,
    C_ACCEPT_INVITATION = 13,
    C_DECLINE_INVITATION = 14,
    C_MODIFY_STATUS = 15,
    C_MODIFY_LOGIN = 16,
    C_MODIFY_LOCATION = 17,
    C_MUTE = 20,
    C_ADD_PARTICIPANT_TO_CALL = 21,
    C_ADD_TO_FAVORITES = 22,
    C_REMOVE_FROM_FAVORITES = 23,
    C_ADD_NICKNAME = 24,
    C_REMOVE_CONTACT = 25,
    C_MODIFY_PROFIL_PICTURE = 26,
    C_SEND_FILE = 30,
    C_LISTEN_TO_MAIL = 31,
    S_SUCCESS_HANDSHAKE = 101,
    S_SUCCESS_ON_SIGN = 102,
    S_ERROR_UNKNOWN = 103,
    S_ERROR_SIGN = 104,
    S_ERROR_CALL = 105,
    S_ERROR_NOT_IMPLEMENTED = 106,
    S_PING = 107,
    S_CONTACT_REQUEST = 108,
    S_CONTACT_INFO = 109,
    S_CALL_REQUEST = 110,
    S_SEND_TEXT = 111,
    S_HANGED_UP = 112,
    S_SEND_FILE = 130
  }            CommunicationType;

  AProcotol();
  ~AProcotol();

  bool  initMethod();
  bool  methodChecker(Server &server, AData &data);

private:

  typedef void(AProtocol::*Funcs)(Server &server, AData &data);
    Funcs _ptr;
    typedef std::map<CommunicationType, Funcs>PointersOnFuncs;
    PointersOnFuncs	        _functions;

};

#endif /* !APROTOCOL_HH_ */
