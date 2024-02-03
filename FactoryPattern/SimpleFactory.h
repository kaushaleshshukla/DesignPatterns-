class PizzaStore {
public:
  Pizza orderPizza(const std::string &type) {
    SimplePizzaFactory factory;
    Pizza pizza = factory.createPizza(type);
    pizza.prepare();
    pizza.bake();
    pizza.cut();
    pizza.box();
    return pizza;
  }

  // other PizzaStore methods here
};

class SimplePizzaFactory {
public:
  Pizza createPizza(const std::string &type) {
    if (type == "cheese") {
      return CheesePizza();
    } else if (type == "pepperoni") {
      return PepperoniPizza();
    } else if (type == "clam") {
      return ClamPizza();
    } else if (type == "veggie") {
      return VeggiePizza();
    } else {
      throw std::invalid_argument("Invalid pizza type");
    }
  }
};