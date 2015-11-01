//
// MutexLocker.hh for MutexLocker in /home/antoinegarcia/rendu/cpp_babel/app/Mutex
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Nov  1 02:33:17 2015 Antoine Garcia
// Last update Sun Nov  1 02:49:40 2015 Antoine Garcia
//

#ifndef MUTEXLOCKER_HH_
# define MUTEXLOCKER_HH_
#include "Mutex.hh"

class	MutexLocker
{
  Mutex	*_mutex;
public:
  MutexLocker(Mutex	*mutex);
  ~MutexLocker();
};

#endif
