//
// CallManager.hh for CallManager in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 28 06:50:08 2015 Antoine Garcia
// Last update Wed Oct 28 06:51:50 2015 Antoine Garcia
//

#ifndef CALLMANAGER_HH_
# define CALLMANAGER_HH_

#include "PTSoundOutput.hh"
class	CallManager
{
  ISoundDevice	*_out;
  ISoundDevice	*_in;
public:
  CallManager(){};
  ~CallManager(){};
};

#endif
