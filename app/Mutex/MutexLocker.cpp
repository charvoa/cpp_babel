//
// MutexLocker.cpp for MutexLocker in /home/antoinegarcia/rendu/cpp_babel/app/Mutex
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Nov  1 02:35:06 2015 Antoine Garcia
// Last update Sun Nov  1 02:47:44 2015 Antoine Garcia
//

#include "MutexLocker.hh"

MutexLocker::MutexLocker(Mutex	*mutex): _mutex(mutex)
{
  _mutex->lock();
}

MutexLocker::~MutexLocker()
{
  _mutex->unlock();
}
