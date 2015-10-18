#ifndef _REQUEST_HH
# define _REQUEST_HH

class		        Request : PTObject
{
  typedef enum	        type
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
    }			type;

  Request(std::string &stringRequest);
  ~Request();

  REQUEST::type	       	getRequestType();  

private:

  REQUEST::type		_type;
  std::string		_data;

};

#endif /* !REQUEST_HH_ */
