#ifndef CONCRETE_OBSERVER1_H_
#define CONCRETE_OBSERVER1_H_

#include "IObserver.h"
#include <iostream>

class ConcreteObserver1 : public IObserver
{
 public:
  void notify() override {
    std::cout << "ConcreteObserver1::notify()" << std::endl;
  }
};

#endif
