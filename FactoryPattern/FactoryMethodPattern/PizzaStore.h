#pragma once

#include "Pizza.h"
#include <string>

class PizzaStore {
public:
  Pizza orderPizza(const std::string &type) {
    Pizza pizza = createPizza(type);
    pizza.prepare();
    pizza.bake();
    pizza.cut();
    pizza.box();
    return pizza;
  }

protected:
  // Factory method needed to be implemented by subclasses
  virtual Pizza createPizza(const std::string &type) = 0;
};

class NYPizzaStore : public PizzaStore {
protected:
  Pizza createPizza(const std::string &type) override {
    if (type == "cheese") {
      return NYStyleCheesePizza();
    } else if (type == "pepperoni") {
      return NYStylePepperoniPizza();
    } else if (type == "clam") {
      return NYStyleClamPizza();
    } else {
      throw std::invalid_argument("Invalid pizza type");
    }
  }
};

class ChicagoPizzaStore : public PizzaStore {
protected:
  Pizza createPizza(const std::string &type) override {
    if (type == "cheese") {
      return ChicagoStyleCheesePizza();
    } else if (type == "pepperoni") {
      return ChicagoStylePepperoniPizza();
    } else if (type == "clam") {
      return ChicagoStyleClamPizza();
    } else {
      throw std::invalid_argument("Invalid pizza type");
    }
  }
};
