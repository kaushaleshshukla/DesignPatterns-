#include <iostream>
using namespace std;

// Interface that all flying behavior classes implements
class flyingBehavior {
public:
  virtual void fly() = 0;
};

class flyWithWings : public flyingBehavior {
public:
  void fly() { cout << "I'm flying with Wings" << endl; }
};

class flyLikeRocket : public flyingBehavior {
public:
  void fly() { cout << "I can fly like Rocket" << endl; }
};

class noFly : public flyingBehavior {
public:
  void fly() { cout << "I can't fly" << endl; }
};
