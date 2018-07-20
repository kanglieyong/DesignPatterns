#ifndef IOBSERVER_H_
#define IOBSERVER_H_

class IObserver
{
 public:
  virtual ~IObserver() = default;
  virtual void notify() = 0;
};

#endif
