#ifndef IOBSERVABLE_SUBJECT_H_
#define IOBSERVABLE_SUBJECT_H_

#include "IObservable.h"

class ObservableSubject : public Observable
{
 public:
  void modify_data()
  {
    notifyAllObservers();
  }
};

#endif
