#include "Decorators.h"

class espresso : public beverage {
public:
  espresso() { description = "Espresso"; }
  float getCost() { return 1.5; }
};

class houseBlend : public beverage {
public:
  houseBlend() { description = "House Blend"; }
  float getCost() { return 1; }
};