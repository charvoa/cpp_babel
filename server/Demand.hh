#ifndef _DEMAND_HH
# define _DEMAND_HH

class		        Demand : PTObject
{

  Demand(std::string &stringDemand);
  ~Demand();

  DEMAND::type	       	getDemandType();  

private:

  type			_type;
  std::string		_data;

};

#endif /* !DEMAND_HH_ */
