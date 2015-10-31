//
// PTSoundInput.cpp for PTSoundInput in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Oct 31 02:06:00 2015 Antoine Garcia
// Last update Sat Oct 31 02:30:37 2015 Antoine Garcia
//

#include "PTSoundInput.hh"
#include <iostream>
PTSoundInput::PTSoundInput()
{
  PaError	err;

  err = Pa_Initialize();
  if (err != paNoError)
    {
      std::cout << "ERROR" << std::endl;
    }
  initInput();
}

PTSoundInput::~PTSoundInput()
{
}

void	PTSoundInput::initInput()
{
  _params.device = Pa_GetDefaultInputDevice();
  _params.channelCount = SoundDevice::channels;
  _params.sampleFormat = paFloat32;
  _params.suggestedLatency = Pa_GetDeviceInfo(_params.device)->defaultLowInputLatency;
  _params.hostApiSpecificStreamInfo = NULL;
}

void	PTSoundInput::start()
{
  PaError	err;
  err = Pa_OpenStream(&_stream,&_params, NULL, SoundDevice::sampleRate,paFramesPerBufferUnspecified, paClipOff,PTSoundInput::recordCallback, this);
  if (err != paNoError)
    {
      std::cout << "ERROR" << std::endl;
    }
  err = Pa_StartStream(_stream);
  if (err != paNoError)
    std::cout <<  Pa_GetErrorText( err ) << std::endl;
}

int PTSoundInput::recordCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,void *userData)
{
  std::cout << "RECORD CALLBACK" << std::endl;
  return paContinue;
}
