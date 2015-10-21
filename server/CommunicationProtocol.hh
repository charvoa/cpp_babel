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

typedef struct	Requests
{
  int				_requestNumber;
  type				_type;
  std::string			_requestSyntax;
  bool				(*ptrFunc)();

};

#endif /* !REQUESTS_HH_ */

// ={
//   {10, SIGN_UP, ":1,:1,n,n", &signUp},
//   {11, SIGN_IN, ":1,:1,n,n", &signIn},
//   {20, CALL, "16,16", &call},
//   {21, MUTE, "16,16,16", &mute},
//   {22, HANG_UP, "16,16", &hangUp},
//   {23, SEND_TEXT, "16,16,:2,n", &sendText},
//   {24, SEND_FILE, "16,16,:4,n", &sendFile},
//   {25, ADD_PARTICIPANT, "16,16", &addParticipant},
//   {30, ADD_CONTACT, ":16,16", &addContact},
//   {31, GET_CONTACT, ":16", &getContact},
//   {32, REMOVE_CONTACT, "16,16", &removeContact},
//   {33, MODIFY_PROFIL_PICTURE, "16,:4,n", &modifyProfilPicture},
//   {34, MODIFY_STATUS, ":16,16", &modifyStatus},
//   {35, MODIFY_LOGIN, ":16,16", &modifyLogin},
//   {36, MODIFY_LOCATION, "16,64", &modifyLocation},
//   {37, ADD_NICKNAME, "16,16,16", &addNickname},
//   {38, LISTEN_TO_MAIL, "16", &listenToMail},
// }

 ={
   {10, SIGN_UP, ":1,:1,n,n", &signUp},
   {11, SIGN_IN, ":1,:1,n,n", &signIn},
   {20, CALL, "16,16", &call},
   {21, MUTE, "16,16,16", &mute},
   {22, HANG_UP, "16,16", &hangUp},
   {23, SEND_TEXT, "16,16,:2,n", &sendText},
   {24, SEND_FILE, "16,16,:4,n", &sendFile},
   {25, ADD_PARTICIPANT, "16,16", &addParticipant},
   {30, ADD_CONTACT, ":16,16", &addContact},
   {31, GET_CONTACT, ":16", &getContact},
   {32, REMOVE_CONTACT, "16,16", &removeContact},
   {33, MODIFY_PROFIL_PICTURE, "16,:4,n", &modifyProfilPicture},
   {34, MODIFY_STATUS, ":16,16", &modifyStatus},
   {35, MODIFY_LOGIN, ":16,16", &modifyLogin},
   {36, MODIFY_LOCATION, "16,64", &modifyLocation},
   {37, ADD_NICKNAME, "16,16,16", &addNickname},
   {38, LISTEN_TO_MAIL, "16", &listenToMail},
}