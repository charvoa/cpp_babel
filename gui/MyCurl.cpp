//
// MyCurl.cpp for  in /home/nicolaschr/rendu/cpp_babel/gui
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Oct 21 17:16:51 2015 Nicolas Charvoz
// Last update Wed Oct 21 17:29:19 2015 Nicolas Charvoz
//

#include "MyCurl.hh"

std::string data;

extern "C" {

  size_t writeFunction(char* buf, size_t size, size_t nmemb, void* up)
  { //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    (void) up;

    for (size_t c = 0; c < (size*nmemb); c++)
      {
	data.push_back(buf[c]);
      }
    return size*nmemb; //tell curl how many bytes we handled
  }
}

MyCurl::MyCurl()
{}

int MyCurl::exec()
{
  CURL* curl; //our curl object
  char *str = "";


  curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
  curl = curl_easy_init();

  curl_easy_setopt(curl, CURLOPT_URL, pathTo);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeFunction);
  curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

  curl_easy_perform(curl);

  std::cout << std::endl << data << std::endl;
  std::cin.get();

  curl_easy_cleanup(curl);
  curl_global_cleanup();

  return 0;
}
