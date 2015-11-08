//
// ISoundDevice.hh for ISoundDevice in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 28 01:57:52 2015 Antoine Garcia
// Last update Sun Nov  8 02:23:32 2015 Antoine Garcia
//

#ifndef ISOUNDDEVICE_HH_
# define ISOUNDDEVICE_HH_

#include "../libs/portaudio.h"

typedef float SAMPLE;
namespace SoundDevice {
  const unsigned int channels = 2;
  const double sampleRate = 48000;
  const unsigned int frame_size = 480;
}

class	ISoundDevice
{
public:
  virtual ~ISoundDevice() {};
  virtual void start() = 0;
  virtual void stop() = 0;
};

#endif
