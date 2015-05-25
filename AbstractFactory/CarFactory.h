#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include "Car.h"

class CarFactory
{
 public:
  CarFactory();
  
  Car* request();
  int getNumCarsInProduction() const;

 protected:
  virtual Car* createCar() = 0;

 private:
  int mNumCarsInProduction;
};

class FordFactory : public CarFactory
{
 protected:
  virtual Car* createCar();
};

class ToyotaFactory : public CarFactory
{
 protected:
  virtual Car* createCar();
};

#endif
