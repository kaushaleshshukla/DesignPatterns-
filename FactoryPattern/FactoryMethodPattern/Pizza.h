#pragma once

#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
  void prepare() {
    std::cout << "Preparing " << name << std::endl;
    std::cout << "Tossing dough..." << std::endl;
    std::cout << "Adding sauce..." << std::endl;
    std::cout << "Adding toppings: " << std::endl;
    for (auto topping : toppings) {
      std::cout << "    " << topping << std::endl;
    }
  }

  void bake() { std::cout << "Bake for 25 minutes at 350" << std::endl; }

  void cut() {
    std::cout << "Cutting the pizza into diagonal slices" << std::endl;
  }

  void box() {
    std::cout << "Place pizza in official PizzaStore box" << std::endl;
  }

  std::string getName() { return name; }

protected:
  std::string name;
  std::string dough;
  std::string sauce;
  std::vector<std::string> toppings;
};

class NYStyleCheesePizza : public Pizza {
public:
  NYStyleCheesePizza() {
    name = "NY Style Sauce and Cheese Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings = {"Grated", "Reggiano", "Cheese"};
  }
};

class ChicagoStyleCheesePizza : public Pizza {
public:
  ChicagoStyleCheesePizza() {
    name = "Chicago Style Deep Dish Cheese Pizza";
    dough = "Extra Thick Crust Dough";
    sauce = "Plum Tomato Sauce";
    toppings = {"Shredded", "Mozzarella", "Cheese"};
  }
};

class NYStylePepperoniPizza : public Pizza {
public:
  NYStylePepperoniPizza() {
    name = "NY Style Pepperoni Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings = {"Grated", "Reggiano", "Cheese",    "Sliced", "Pepperoni",
                "Garlic", "Onion",    "Mushrooms", "Red",    "Pepper"};
  }
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
  ChicagoStylePepperoniPizza() {
    name = "Chicago Style Pepperoni Pizza";
    dough = "Extra Thick Crust Dough";
    sauce = "Plum Tomato Sauce";
    toppings = {"Shredded", "Mozzarella", "Cheese", "Black",    "Olives",
                "Spinach",  "Eggplant",   "Sliced", "Pepperoni"};
  }
};

class NYStyleClamPizza : public Pizza {
public:
  NYStyleClamPizza() {
    name = "NY Style Clam Pizza";
    dough = "Thin Crust Dough";
    sauce = "Marinara Sauce";
    toppings = {"Grated", "Reggiano", "Cheese", "Fresh", "Clams",
                "from",   "Long",     "Island", "Sound"};
  }
};

class ChicagoStyleClamPizza : public Pizza {
public:
  ChicagoStyleClamPizza() {
    name = "Chicago Style Clam Pizza";
    dough = "Extra Thick Crust Dough";
    sauce = "Plum Tomato Sauce";
    toppings = {"Shredded", "Mozzarella", "Cheese",     "Frozen",
                "Clams",    "from",       "Chesapeake", "Bay"};
  }
};