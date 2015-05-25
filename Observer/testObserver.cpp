#include "EventRegistry.h"
#include "TestListener.h"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
  TestListener tl;
  EventRegistry::handleMessage(0);
  EventRegistry::handleMessage(1);
  EventRegistry::handleMessage(2);

  if (!tl.bMessage0Received) {
    cout << "TEST FAILED: Message 0 was not received" << endl;
  } else if (tl.bUnkownMessageReceived) {
    cout << "TEST FAILED: TestListener received unkown message" << endl;
  } else {
    cout << "TEST PASSED" << endl;
  }
  
  return 0;
}
