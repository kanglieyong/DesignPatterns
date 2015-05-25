#include "TestListener.h"
#include "EventRegistry.h"

TestListener::TestListener()
  : bMessage0Received(false),
    bUnkownMessageReceived(false)
{
  EventRegistry::registerListener(0, this);
}

void TestListener::handleMessage(int inMessage)
{
  switch (inMessage) {
  case 0:
    bMessage0Received = true;
    break;

  default:
    bUnkownMessageReceived = true;
    break;
  }
}
