//
// ISoundDevice.hh for ISoundDevice in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 28 01:57:52 2015 Antoine Garcia
// Last update Wed Oct 28 03:45:43 2015 Antoine Garcia
//

#ifndef ISOUNDDEVICE_HH_
# define ISOUNDDEVICE_HH_

#include "../libs/portaudio.h"

namespace SoundDevice {
  const unsigned int channels = 2;
  const double sampleRate = 44100;
}

class	ISoundDevice
{
public:
  virtual ~ISoundDevice() {};
  virtual void start() = 0;
  virtual void stop() = 0;
};

#endif
