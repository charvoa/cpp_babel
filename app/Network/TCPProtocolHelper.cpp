//
// TCPProtocolHelper.cpp for TCPProtocolHelper in /home/antoinegarcia/rendu/cpp_babel/app/Network
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Oct 20 06:54:26 2015 Antoine Garcia
// Last update Tue Oct 20 07:06:34 2015 Antoine Garcia
//

#include "TCPProtocolHelper.hh"

TCPProtolHelper::TCPProtolHelper(const std::string &data)
{
  if (data != NULL){
      _data = data;
    }
}

~TCPProtolHelper()
{}

const std::string&	getData()
{
  return (_data);
}
