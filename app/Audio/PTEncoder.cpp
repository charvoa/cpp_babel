//
// PTEncoder.cpp for PTEncoder in /home/antoinegarcia/rendu/cpp_babel/app/Audio
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Oct 31 03:17:51 2015 Antoine Garcia
// Last update Sun Nov  8 07:35:35 2015 Antoine Garcia
//

#include "PTEncoder.hh"

PTEncoder::PTEncoder()
{
  _encode = opus_encoder_create(SoundDevice::sampleRate, SoundDevice::channels, OPUS_APPLICATION_VOIP, NULL);
  _decode = opus_decoder_create(Sound::sampleRate, Sound::channels, NULL);
}

PTEncoder::~PTEncoder()
{

}

soundEncoded	encode(soundDecoded sound)
{
  soundEncoded	encode;

  encode.buffer.resize(sound.size);
  encode.size = opus_encode_float(_encode,sound.buffer.data(), SoundDevice::frame_size, encode.buffer.data(), sound.size);
  return encode;
}

soundDecoded	decode(soundEncoded sound)
{
  soundDecoded	decode;

  decode.buffer.resize(sound.size);
  decode.size = opus_decode_float(_decode,sound.buffer.data(), sound.size(), decode.buffer.data(), soundDecoded::frame_size, 0) * SoundDevice::channels;
  return decode;
}
