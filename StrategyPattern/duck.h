#include "flyingBehavior.h"
#include "quackingBehavior.h"
#include <iostream>

using namespace std;

// interface that all duck classes implements.
class duck {
private:
  // favour composition over inheritence
  quackingBehavior *quackBehavior;
  flyingBehavior *flyBehavior;

public:
  virtual void display() = 0;

  void performFly() { flyBehavior->fly(); }

  void performQuack() { quackBehavior->sound(); }

  void setQuackBehavior(quackingBehavior *newQuackBehavior) {
    quackBehavior = newQuackBehavior;
  }

  void setFlyBehavior(flyingBehavior *newFlyBehavior) {
    flyBehavior = newFlyBehavior;
  }

  void performSwim() { cout << "Every duck can swim" << endl; }
};

class mallardDuck : public duck {
public:
  mallardDuck() {
    setQuackBehavior(new quack());
    setFlyBehavior(new flyWithWings());
  }

  void display() { cout << "Hey, I'm Mallard Duck" << endl; }
};

class modelDuck : public duck {
public:
  modelDuck() {
    setQuackBehavior(new squeak());
    setFlyBehavior(new noFly());
  }

  void display() { cout << "Hey, I'm Model duck" << endl; }
};

class rocketDuck : public duck {
public:
  rocketDuck() {
    setQuackBehavior(new mute());
    setFlyBehavior(new flyLikeRocket());
  }

  void display() { cout << "Hey, I'm duck with rocket speed" << endl; }
};