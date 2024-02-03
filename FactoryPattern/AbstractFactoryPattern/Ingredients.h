#pragma once

#include <iostream>

class Veggies {
public:
  Veggies() { std::cout << "Veggie" << std::endl; }
};

class Dough {
public:
  virtual void type() = 0;
};

class ThinCrustDough : public Dough {
public:
  ThinCrustDough() { type(); }
  void type() { std::cout << "ThinCrustDough" << std::endl; }
};

class ThickCrustDough : public Dough {
public:
  ThickCrustDough() { type(); }
  void type() { std::cout << "ThickCrustDough" << std::endl; }
};

class Pepperoni {
public:
  virtual void type() = 0;
};

class SlicedPepperoni : public Pepperoni {
public:
  SlicedPepperoni() { type(); }
  void type() { std::cout << "SlicedPepperoni" << std::endl; }
};

class Sauce {
public:
  virtual void type() = 0;
};

class MarinaraSauce : public Sauce {
public:
  MarinaraSauce() { type(); }
  void type() { std::cout << "MarinaraSauce" << std::endl; }
};

class PlumTomatoSauce : public Sauce {
public:
  PlumTomatoSauce() { type(); }
  void type() { std::cout << "PlumTomatoSauce" << std::endl; }
};

class Cheese {
public:
  virtual void type() = 0;
};

class ReggianoCheese : public Cheese {
public:
  ReggianoCheese() { type(); }
  void type() { std::cout << "ReggianoCheese" << std::endl; }
};

class MozzarellaCheese : public Cheese {
public:
  MozzarellaCheese() { type(); }
  void type() { std::cout << "MozzarellaCheese" << std::endl; }
};

class Clams {
public:
  virtual void type() = 0;
};

class FreshClams : public Clams {
public:
  FreshClams() { type(); }
  void type() { std::cout << "FreshClams" << std::endl; }
};

class FrozenClams : public Clams {
public:
  FrozenClams() { type(); }
  void type() { std::cout << "FrozenClams" << std::endl; }
};