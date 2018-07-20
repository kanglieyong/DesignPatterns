#include <iostream>

#include "IObserver.h"
#include "ConcreteObserver1.h"
#include "ConcreteObserver2.h"
#include "ObservableSubject.h"

int main()
{
  ObservableSubject subject;
  ConcreteObserver1 o1;
  ConcreteObserver2 o2;

  subject.addObserver(&o1);
  subject.modify_data();

  std::cout << std::endl;

  subject.addObserver(&o2);
  subject.modify_data();

  return 0;
}
