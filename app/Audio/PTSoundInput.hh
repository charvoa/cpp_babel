//
// PTSoundInput.hh for PTSoundInput in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Oct 31 01:57:23 2015 Antoine Garcia
// Last update Sat Oct 31 02:25:52 2015 Antoine Garcia
//

#ifndef PTSOUNDINPUT_HH_
# define PTSOUNDINPUT_HH_

#include "ISoundDevice.hh"

class	PTSoundInput : public ISoundDevice
{
  PaStream	*_stream;
  PaStreamParameters	_params;
  void			initInput();
  static int recordCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,void *userData);
public:
  PTSoundInput();
  ~PTSoundInput();
  void	start();
  void	stop(){};
};

#endif
