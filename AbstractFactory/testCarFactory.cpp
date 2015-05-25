#include "CarFactory.h"
#include <vector>
#include <memory>

using std::vector;
using std::make_shared;
using std::shared_ptr;

shared_ptr<CarFactory> getLeastBusyFactory(const vector<shared_ptr<CarFactory> >& inFactories)
{
  if (inFactories.size() == 0) return nullptr;
  shared_ptr<CarFactory> bestSoFar = inFactories[0];
  for (size_t i = 1; i < inFactories.size(); i++) {
    if (inFactories[i]->getNumCarsInProduction() < bestSoFar->getNumCarsInProduction()) bestSoFar = inFactories[i];
  }
  return bestSoFar;
}

int main(void)
{
  vector<shared_ptr<CarFactory> > factories;

  auto factory1 = make_shared<FordFactory>();
  auto factory2 = make_shared<FordFactory>();
  auto factory3 = make_shared<FordFactory>();
  auto factory4 = make_shared<ToyotaFactory>();

  factory1->requestCar();
  factory1->requestCar();
  factory2->requestCar();
  factory4->requestCar();

  factories.push_back(factory1);
  factories.push_back(factory2);
  factories.push_back(factory3);
  factories.push_back(factory4);

  for (size_t i = 0; i < 10; i++) {
    shared_ptr<CarFactory> currentFactory = getLeastBusyFactory(factories);
    shared_ptr<Car> theCar(currentFactory->requestCar());
    theCar->info();
  }
  
  return 0;
}
