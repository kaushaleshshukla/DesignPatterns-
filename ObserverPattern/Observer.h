#include <iostream>
using namespace std;

// observer interface
class observer {
public:
  virtual void update(float temprature, float pressure, float humidity) = 0;
  virtual void display() = 0;
};
