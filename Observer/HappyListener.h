#ifndef HAPPY_LISTENER_H_
#define HAPPY_LISTENER_H_

#include "Listener.h"

class HappyListener : public Listener
{
 public:
  HappyListener();

  void handleMessage(int inMessage);
};

#endif
