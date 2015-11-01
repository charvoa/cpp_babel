//
// Network.hpp for babel in /home/nicolas/rendu/cpp_babel/server/Common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Oct 20 15:52:59 2015 Nicolas Girardot
// Last update Sat Oct 31 21:37:23 2015 Nicolas Girardot
//

#ifndef NETWORK_HH_
# define NETWORK_HH_

# include "INetwork.hh"
# include "TCPServer.hpp"
# include <boost/bind.hpp>
# include <boost/shared_ptr.hpp>
# include <boost/enable_shared_from_this.hpp>
# include <boost/asio.hpp>

class		Network : public INetwork
{
public:
  Network() {};

  virtual ~Network() {};

  virtual void start()
  {
    try
      {
	boost::asio::io_service ioService;
	_server = new TCPServer(ioService);
	ioService.run();
      }
    catch (std::exception& e)
      {
	std::cerr << e.what() << std::endl;
      }
  }

  virtual void write(const std::string &message)
  {
    (void) message;
  }

  virtual void read()
  {
  }

  TCPServer	*getServer()
  {
    return _server;
  }

private:
  TCPServer *_server;
};

#endif
