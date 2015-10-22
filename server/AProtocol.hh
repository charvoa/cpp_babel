#ifndef _APROTOCOL_HH
# define _APROTOCOL_HH

#include <string>

class		        AProcotol
{

  typedef enum CommunicationType {
    C_HANDSHAKE = 1,
    C_SUCCESS = 2,
    C_ERROR = 3,
    C_SIGNUP = 4,
    C_SIGNIN = 5,
    C_CALL = 6,
    C_HANGUP = 7,
    C_SEND_TEXT = 8,
    C_PONG = 9,
    C_ACCEPT_CALL = 10,
    C_DECLINE_CALL = 11,
    C_ADD_CONTACT = 12,
    C_MODIFY_STATUS = 13,
    C_MODIFY_LOGIN = 14,
    C_MODIFY_LOCATION = 15,
    C_MUTE = 20,
    C_ADD_PARTICIPANT_TO_CALL = 21,
    C_ADD_TO_FAVORITES = 22,
    C_ADD_NICKNAME = 23,
    C_REMOVE_CONTACT = 24,
    C_MODIFY_PROFIL_PICTURE = 25,
    C_SEND_FILE = 30,
    C_LISTEN_TO_MAIL = 31,
    // METTRE LES ENUM SERVEUR
  }            CommunicationType;

  AProcotol();
  ~AProcotol();

  bool  initMethod();
  bool  methodChecker(Server &server, AData &data);

private:

  typedef void(AProtocol::*Funcs)(Server &server, AData &data);
    Funcs _ptr;
    typedef std::map<CommunicationType, Funcs>MapFuncs;
    MapFuncs	_functions;

};

#endif /* !APROTOCOL_HH_ */
