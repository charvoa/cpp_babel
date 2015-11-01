//
// Mutex.hh for Mutex in /home/antoinegarcia/rendu/cpp_babel/app/Mutex
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Nov  1 01:08:31 2015 Antoine Garcia
// Last update Sun Nov  1 01:15:23 2015 Antoine Garcia
//

#ifndef MUTEX_HH_
# define MUTEX_HH_
#include <QMutex>

class	Mutex
{
  QMutex	_mutex;
public:
  Mutex(){}
  ~Mutex(){}
  void	lock();
  void	unlock();
  bool	tryLock(int timeout = -1);
};

#endif
