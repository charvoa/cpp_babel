//
// Audio.hh for Audio in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Oct 19 00:32:40 2015 Antoine Garcia
// Last update Mon Oct 19 00:45:52 2015 Antoine Garcia
//

#ifndef AUDIO_HH_
# define AUDIO_HH_

#include "portaudio.h"

class	Audio
{
  PaError	_err;
public:
  Audio()
  ~Audio()
  init();
  start();
}

#endif
