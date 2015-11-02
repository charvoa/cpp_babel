//
// Mutex.cpp for Mutex in /home/antoinegarcia/rendu/cpp_babel/app/Mutex
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Nov  1 01:11:26 2015 Antoine Garcia
// Last update Sun Nov  1 01:15:46 2015 Antoine Garcia
//

#include "Mutex.hh"

void	Mutex::lock()
{
  _mutex.lock();
}

void	Mutex::unlock()
{
  _mutex.unlock();
}

bool	Mutex::tryLock(int timeout)
{
 return  _mutex.tryLock(timeout);
}
