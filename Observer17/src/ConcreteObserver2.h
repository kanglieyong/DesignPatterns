#ifndef CONCRETE_OBSERVER2_H_
#define CONCRETE_OBSERVER2_H_

#include "IObserver.h"

#include <iostream>

class ConcreteObserver2 : public IObserver
{
 public:
  void notify() override {
    std::cout << "ConcreteObserver2::notify()" << std::endl;
  }
};

#endif
