//
// PTEncoder.hh for PTEncoder in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Oct 31 03:14:05 2015 Antoine Garcia
// Last update Sat Oct 31 03:20:17 2015 Antoine Garcia
//

#ifndef PTENCODER_HH_
# define PTENCODER_HH_

#include "IEncoder.hh"
class	PTEncoder : public IEncoder
{
  OpusEncoder	*_encode;
public:
  PTEncoder();
  ~PTEncoder();
};

#endif