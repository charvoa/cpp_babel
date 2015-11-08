//
// PTEncoder.hh for PTEncoder in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Oct 31 03:14:05 2015 Antoine Garcia
// Last update Sun Nov  8 07:23:59 2015 Antoine Garcia
//

#ifndef PTENCODER_HH_
# define PTENCODER_HH_

#include "IEncoder.hh"
class	PTEncoder : public IEncoder
{
  OpusEncoder	*_encode;
  OpusDecoder	*_decode;
public:
  PTEncoder();
  ~PTEncoder();
  soundEncoded	encode(soundDecoded sound);
  soundDecoded	decode(soundEncoded sound);
};

#endif
