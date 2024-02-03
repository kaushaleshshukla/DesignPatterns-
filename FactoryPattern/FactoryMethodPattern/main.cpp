#include "PizzaStore.h"

using namespace std;

int main() {
  PizzaStore *nyStore = new NYPizzaStore();
  PizzaStore *chicagoStore = new ChicagoPizzaStore();

  Pizza pizza = nyStore->orderPizza("cheese");
  cout << "Ethan ordered a " << pizza.getName() << endl;

  pizza = chicagoStore->orderPizza("cheese");
  cout << "Joel ordered a " << pizza.getName() << endl;

  return 0;
}