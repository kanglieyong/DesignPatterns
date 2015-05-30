#include "HappyListener.h"
#include "EventRegistry.h"
#include <iostream>

using std::cout;
using std::endl;

HappyListener::HappyListener()
{
  EventRegistry::registerListener(0, this);
}

void HappyListener::handleMessage(int inMessage)
{
  cout << "inMessage = " << inMessage << endl;
}
