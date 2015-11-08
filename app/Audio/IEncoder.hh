//
// IEncoder.hh for IEncoder in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Oct 31 03:00:38 2015 Antoine Garcia
// Last update Sun Nov  8 02:21:32 2015 Antoine Garcia
//

#ifndef IENCODER_HH_
# define IENCODER_HH_

#include "../libs/opus.h"
#include <vector>
typedef struct soundEncoded
{
  std::vector<unsigned char> buffer;
  int			     size;
}		soundEncoded;
typedef struct soundDecoded
{
  std::vector<float> buffer;
  int			     size;
}		soundDecoded;

class	IEncoder
{
public:
  virtual ~IEncoder(){};
};

#endif
