#include "CarFactory.h"

CarFactory::CarFactory()
  : mNumCarsInProduction(0)
{}

Car* CarFactory::requestCar()
{
  mNumCarsInProduction++;
  return createCar();
}

int CarFactory::getNumCarsInProduction() const
{
  return mNumCarsInProduction;
}

Car* FordFactory::createCar()
{
  return new Ford();
}

Car* ToyotaFactory::createCar()
{
  return new Toyota();
}
