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
