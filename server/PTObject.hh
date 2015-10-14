#ifndef _PTOBJECT_HH_
# define _PTOBJECT_HH_

#include <string>

class		        PTObject
{

  PTObject();
  ~PTObject();

  std::string		&getObjectID();

private:

  std::string		_objectID;

};

#endif /* !PTObject_HH_ */
