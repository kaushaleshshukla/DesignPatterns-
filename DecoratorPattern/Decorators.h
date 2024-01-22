#include "superBeverageClass.h"
#include <bits/stdc++.h>
// Decorator extending beverage class to match the type of beverages.
class decorator : public beverage {
public:
  beverage *Beverage;
  // virtual string getDescription() = 0;
};

class mocha : public decorator {
public:
  mocha(beverage *Beverage) { this->Beverage = Beverage; }
  string getDescription() { return Beverage->getDescription() + " with Mocha"; }

  float getCost() { return Beverage->getCost() + 0.5; }
};

class soy : public decorator {
public:
  soy(beverage *Beverage) { this->Beverage = Beverage; }

  string getDescription() { return Beverage->getDescription() + " with Soy"; }

  float getCost() { return Beverage->getCost() + 0.3; }
};

class whip : public decorator {
public:
  whip(beverage *Beverage) { this->Beverage = Beverage; }

  string getDescription() { return Beverage->getDescription() + " with Whip"; }

  float getCost() { return Beverage->getCost() + 0.7; }
};