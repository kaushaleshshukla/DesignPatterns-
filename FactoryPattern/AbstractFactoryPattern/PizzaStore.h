#pragma once

#include "Pizza.h"
#include "PizzaIngredientFactory.h"

class PizzaStore {
public:
  Pizza *orderPizza(std::string type) {
    Pizza *pizza;
    pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
  }
  virtual Pizza *createPizza(std::string type) = 0;
};

class NYPizzaStore : public PizzaStore {
public:
  Pizza *createPizza(std::string type) {
    Pizza *pizza = nullptr;
    auto ingredientFactory = std::make_shared<NYPizzaIngredientFactory>();
    if (type == "cheese") {
      pizza = new CheesePizza(ingredientFactory);
      pizza->setName("New York Style Cheese Pizza");
    } else if (type == "veggie") {
      pizza = new VeggiePizza(ingredientFactory);
      pizza->setName("New York Style Veggie Pizza");
    }
    return pizza;
  }
};

class ChicagoPizzaStore : public PizzaStore {
public:
  Pizza *createPizza(std::string type) {
    Pizza *pizza = nullptr;
    auto ingredientFactory = std::make_shared<ChicagoPizzaIngredientFactory>();
    if (type == "cheese") {
      pizza = new CheesePizza(ingredientFactory);
      pizza->setName("Chicago Style Cheese Pizza");
    } else if (type == "veggie") {
      pizza = new VeggiePizza(ingredientFactory);
      pizza->setName("Chicago Style Veggie Pizza");
    }
    return pizza;
  }
};