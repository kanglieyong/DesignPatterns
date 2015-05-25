#ifndef EVENTREGISTRY_H_
#define EVENTREGISTRY_H_

#include "Listener.h"

#include <vector>
#include <map>

class EventRegistry
{
 public:
  static void registerListener(int inMessage, Listener* inListener);
  static void handleMessage(int inMessage);

 protected:
  static std::map<int, std::vector<Listener*> > sListenerMap;
};

#endif
