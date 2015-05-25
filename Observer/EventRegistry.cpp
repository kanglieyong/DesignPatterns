#include "EventRegistry.h"

using std::vector;
using std::map;

map<int, vector<Listener*> > EventRegistry::sListenerMap;

void EventRegistry::registerListener(int inMessage, Listener* inListener)
{
  sListenerMap[inMessage].push_back(inListener);
}

void EventRegistry::handleMessage(int inMessage)
{
  if (sListenerMap.find(inMessage) == sListenerMap.end()) return;
  for (auto iter = sListenerMap[inMessage].begin(); iter != sListenerMap[inMessage].end(); ++iter) {
    (*iter)->handleMessage(inMessage);
  }
}
