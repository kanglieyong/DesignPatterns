#ifndef IOBSERVABLE_H_
#define IOBSERVABLE_H_

#include <vector>
#include <functional>

#include "IObserver.h"

class Observable
{
 public:
  virtual ~Observable() = default;

  void addObserver(IObserver *o)
  {
    observers_.push_back(o);
  }

  void removeObserver(IObserver *o)
  {
    observers_.erase(std::remove(begin(observers_), end(observers_), o),
		     end(observers_));
  }

 protected:
  void notifyAllObservers()
  {
    for (auto *o : observers_)
      o->notify();
  }

 private:
  std::vector<IObserver*> observers_;
};

#endif
