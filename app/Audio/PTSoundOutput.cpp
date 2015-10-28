//
// PTSoundOutput.cpp for PTSoundOutput in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Oct 28 02:44:30 2015 Antoine Garcia
// Last update Wed Oct 28 03:55:40 2015 Antoine Garcia
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
}

void PTSoundOutput::start()
{
  // PaError	err;

  //err = Pa_OpenStream(&stream, NULL, _params, SoundDevice::sampleRate, 512, PTSoundOutput::playCallback,
}

void PTSoundOutput::stop()
{

}
