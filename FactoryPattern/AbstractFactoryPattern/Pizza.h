#pragma once

#include "Ingredients.h"
#include "PizzaIngredientFactory.h"
#include <iostream>
#include <memory>
#include <string>

class Pizza {
public:
  virtual void prepare() = 0;

  void bake() { std::cout << "Bake for 25 minutes at 350" << std::endl; }

  void cut() {
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
  }

  void box() {
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
  }

  std::string getName() { return name; }

  void setName(const std::string &name) { this->name = name; }

protected:
  std::shared_ptr<PizzaIngredientFactory> ingredientFactory;
  std::string name;
  std::shared_ptr<Dough> dough;
  std::shared_ptr<Sauce> sauce;
  std::shared_ptr<Cheese> cheese;
  std::shared_ptr<Pepperoni> pepperoni;
  std::shared_ptr<Clams> clams;
};

class CheesePizza : public Pizza {
public:
  CheesePizza(std::shared_ptr<PizzaIngredientFactory> ingredientFactory) {
    this->ingredientFactory = ingredientFactory;
  }

  void prepare() override {
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough();
    sauce = ingredientFactory->createSauce();
    cheese = ingredientFactory->createCheese();
    pepperoni = ingredientFactory->createPepperoni();
    clams = ingredientFactory->createClams();
  }
};

class VeggiePizza : public Pizza {
public:
  VeggiePizza(std::shared_ptr<PizzaIngredientFactory> ingredientFactory) {
    this->ingredientFactory = ingredientFactory;
  }

  void prepare() override {
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough();
    sauce = ingredientFactory->createSauce();
    cheese = ingredientFactory->createCheese();
    pepperoni = ingredientFactory->createPepperoni();
    clams = ingredientFactory->createClams();
  }
};