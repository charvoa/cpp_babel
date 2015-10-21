//
// MyCurl.hpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:05:14 2015 Nicolas Charvoz
// Last update Wed Oct 21 17:19:53 2015 Nicolas Charvoz
//

#ifndef MYCURL_HH_
# define MYCURL_HH_

# include <iostream>
# include <string>
# include <curl/curl.h>

class MyCurl {

public:

  MyCurl();
  ~MyCurl();
  int exec();

private:

};

#endif
