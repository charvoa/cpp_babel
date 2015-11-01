//
// DataToClient.hh for cpp_babel in /Users/sergeheitzler/Documents/Serge/Work/Git-Repositories/cpp_babel/server/
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.eu>
//
// Started on  Sat Oct 31 16:43:44 2015 Serge Heitzler
// Last update Sat Oct 31 16:44:31 2015 Serge Heitzler
//

#ifndef _DATATOCLIENT_HH
# define _DATATOCLIENT_HH

class			DataToClient : public AData
{

  DataToClient();
  ~DataToClient();

private:

  std::vector<std::string> _data;

};

#endif /* !DATATOCLIENT_HH_ */
