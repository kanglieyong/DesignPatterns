#ifndef LISTENER_H_
#define LISTENER_H_

class Listener
{
 public:
  virtual void handleMessage(int inMessage) = 0;
};

#endif
