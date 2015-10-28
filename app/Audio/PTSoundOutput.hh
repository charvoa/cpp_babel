//
// PTSoundOutput.hh for PTSoundOutput in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 28 02:41:38 2015 Antoine Garcia
// Last update Wed Oct 28 06:21:17 2015 Antoine Garcia
//

#include "ISoundDevice.hh"

class	PTSoundOutput : public ISoundDevice
{
private:
  PaStream	*_stream;
  PaStreamParameters	_params;
  void initOutput();
  static int playCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,void *userData);
public:
  PTSoundOutput();
  ~PTSoundOutput();
  void	start();
  void	stop();
};
