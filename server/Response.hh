#ifndef _RESPONSE_HH
# define _RESPONSE_HH

class		        Response : PTObject
{
    typedef enum	        type
    {
      SUCCESS,
      ERROR,
      ERROR,
      ERROR,
      ERROR,
      ERROR,
      ERROR,
      ERROR,
      ERROR,
    }			type;

  Response(Request &request);
  ~Response();

private:

  


};

#endif /* !RESPONSE_HH_ */
