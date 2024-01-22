#include "duck.h"
#include <iostream>

using namespace std;

int main() {
  mallardDuck *MallardDuck = new mallardDuck();
  MallardDuck->display();
  MallardDuck->performFly();
  MallardDuck->performQuack();
  MallardDuck->performSwim();

  // changing behavior dynamically
  MallardDuck->setFlyBehavior(new flyLikeRocket());
  MallardDuck->performFly();

  modelDuck *ModelDuck = new modelDuck();
  ModelDuck->display();
  ModelDuck->performFly();
  ModelDuck->performQuack();
  ModelDuck->performSwim();

  // changing behavior dynamically
  ModelDuck->setQuackBehavior(new quack());
  ModelDuck->performQuack();

  return 0;
}