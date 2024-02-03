#pragma once

#include "Ingredients.h"
#include <memory>

class PizzaIngredientFactory {
public:
  virtual std::shared_ptr<Dough> createDough() = 0;
  virtual std::shared_ptr<Sauce> createSauce() = 0;
  virtual std::shared_ptr<Cheese> createCheese() = 0;
  virtual std::shared_ptr<Veggies> createVeggies() = 0;
  virtual std::shared_ptr<Pepperoni> createPepperoni() = 0;
  virtual std::shared_ptr<Clams> createClams() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
  std::shared_ptr<Dough> createDough() {
    return std::make_shared<ThinCrustDough>();
  }
  std::shared_ptr<Sauce> createSauce() {
    return std::make_shared<MarinaraSauce>();
  }
  std::shared_ptr<Cheese> createCheese() {
    return std::make_shared<ReggianoCheese>();
  }
  std::shared_ptr<Veggies> createVeggies() {
    return std::make_shared<Veggies>();
  }
  std::shared_ptr<Pepperoni> createPepperoni() {
    return std::make_shared<SlicedPepperoni>();
  }
  std::shared_ptr<Clams> createClams() {
    return std::make_shared<FreshClams>();
  }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
  std::shared_ptr<Dough> createDough() {
    return std::make_shared<ThickCrustDough>();
  }
  std::shared_ptr<Sauce> createSauce() {
    return std::make_shared<PlumTomatoSauce>();
  }
  std::shared_ptr<Cheese> createCheese() {
    return std::make_shared<MozzarellaCheese>();
  }
  std::shared_ptr<Veggies> createVeggies() {
    return std::make_shared<Veggies>();
  }
  std::shared_ptr<Pepperoni> createPepperoni() {
    return std::make_shared<SlicedPepperoni>();
  }
  std::shared_ptr<Clams> createClams() {
    return std::make_shared<FrozenClams>();
  }
};