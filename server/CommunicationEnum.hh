//
// CommunicationEnum.hh for Babel in /home/nicolas/rendu/cpp_babel/server
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Oct 31 17:10:43 2015 Nicolas Girardot
// Last update Sat Oct 31 17:21:09 2015 Nicolas Girardot
//

#ifndef _COMMUNICATIONENUM_HH_
#define _COMMUNICATIONENUM_HH_

typedef enum CommunicationClient {
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
  C_LISTEN_TO_MAIL = 31
}            CommunicationClient;

#endif
