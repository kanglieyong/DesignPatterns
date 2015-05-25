#ifndef TEST_LISTENER_H_
#define TEST_LISTENER_H_

#include "Listener.h"

class TestListener : public Listener
{
 public:
  TestListener();

  void handleMessage(int inMessage);

  bool bMessage0Received;
  bool bUnkownMessageReceived;
};

#endif
