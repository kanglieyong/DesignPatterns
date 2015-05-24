#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
 public:
  static Singleton* Instance();

 protected:
  Singleton() {}
  ~Singleton() { delete _instance; }

 private:
  static Singleton* _instance;
};

#endif

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance()
{
  if (_instance == 0) _instance = new Singleton();
  
  return _instance;
}
