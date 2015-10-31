//
// PTSoundOutput.cpp for PTSoundOutput in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 28 02:44:30 2015 Antoine Garcia
// Last update Sat Oct 31 02:25:20 2015 Antoine Garcia
//

#include <iostream>
#include "PTSoundOutput.hh"

PTSoundOutput::PTSoundOutput()
{
  PaError	err;

  err = Pa_Initialize();
  if (err != paNoError)
    {
      std::cout << "ERROR" << std::endl;
    }
  else {
    initOutput();
  }
}

PTSoundOutput::~PTSoundOutput()
{

}

void PTSoundOutput::initOutput()
{
  _params.device = Pa_GetDefaultOutputDevice();
  if (_params.device == paNoDevice)
    {
      std::cout << "NO DEVICE FOUND" << std::endl;
    }
  _params.channelCount = SoundDevice::channels;
  _params.sampleFormat = paFloat32;
  _params.suggestedLatency = Pa_GetDeviceInfo(_params.device)->defaultLowOutputLatency;
  _params.hostApiSpecificStreamInfo = NULL;
}

void PTSoundOutput::start()
{
  std::cout << "coucou" << std::endl;
   PaError	err;

   err = Pa_OpenStream(&_stream, NULL, &_params, SoundDevice::sampleRate, 256, paClipOff, PTSoundOutput::playCallback,this);
   if (err != paNoError)
     std::cout <<  Pa_GetErrorText( err ) << std::endl;
   err = Pa_StartStream(_stream);
   if (err != paNoError)
     std::cout <<  Pa_GetErrorText( err ) << std::endl;
}

void PTSoundOutput::stop()
{

}


int PTSoundOutput::playCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,void *userData)
{
  return paContinue;
}
