#include "PizzaStore.h"

int main() {
  PizzaStore *nyStore = new NYPizzaStore();
  PizzaStore *chicagoStore = new ChicagoPizzaStore();

  Pizza *pizza = nyStore->orderPizza("cheese");
  std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

  pizza = chicagoStore->orderPizza("cheese");
  std::cout << "Joel ordered a " << pizza->getName() << std::endl;

  return 0;
}