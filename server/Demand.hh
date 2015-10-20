//
// Demand.hh for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Oct 19 10:45:35 2015 Nicolas Girardot
// Last update Mon Oct 19 10:55:02 2015 Nicolas Girardot
//

#ifndef _DEMAND_HH
# define _DEMAND_HH

#include "Requests.hh"

class		        Demand : public PTObject
{
public:
  Demand(std::string &stringDemand);
  ~Demand();

  Requests::type	       	getDemandType();

private:

  type			_type;
  std::string		_data;

};

#endif /* !DEMAND_HH_ */
