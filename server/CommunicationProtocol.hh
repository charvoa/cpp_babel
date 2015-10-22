//
// Requests.hh for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 19 10:51:38 2015 Nicolas Girardot
// Last update Tue Oct 20 06:48:44 2015 Antoine Garcia
//


#ifndef _REQUESTS_HH
# define _REQUESTS_HH

typedef struct	Requests
{
  int				_requestNumber;
  type				_type;
  std::string			_requestSyntax;
  bool				(*ptrFunc)();

};

#endif /* !REQUESTS_HH_ */


 ={
   {1, HANDSHAKE, ":2,:1,n,n", &signUp},
   {10, SUCCESS, ":2,:1,n,n", &signUp},
   {10, ERROR, ":2,:1,n,n", &signUp},
   {10, SIGN_UP, ":2,:1,n,n", &signUp},
   {11, SIGN_IN, ":2,:1,n,n", &signIn},
   {20, CALL, "4,4", &call},
   {22, HANG_UP, "4,4", &hangUp},
   {23, SEND_TEXT, "4,4,:2,n", &sendText},
   {21, MUTE, "4,4,4", &mute},
   {25, ADD_PARTICIPANT, "4,4", &addParticipant},
   {24, SEND_FILE, "4,4,:4,n", &sendFile},
   {24, PONG, ":2,n", &sendFile},
   {30, ACCEPT_CALL, ":4,4", &addContact},
   {30, DECLINE_CALL, ":4,4", &addContact},
   {30, ADD_CONTACT, ":4,4", &addContact},
   {34, MODIFY_STATUS, ":4,4", &modifyStatus},
   {35, MODIFY_LOGIN, ":4,4", &modifyLogin},
   {36, MODIFY_LOCATION, "4,64", &modifyLocation},
   {37, ADD_TO_FAVORITES, "4,4,4", &addNickname},
   {37, ADD_NICKNAME, "4,4,4", &addNickname},
   {32, REMOVE_CONTACT, "4,4", &removeContact},
   {33, MODIFY_PROFIL_PICTURE, "4,:4,n", &modifyProfilPicture},
   {38, LISTEN_TO_MAIL, "4", &listenToMail},
}
