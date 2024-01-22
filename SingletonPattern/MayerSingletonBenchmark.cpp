#include <chrono>
#include <iostream>
#include <time.h>
using namespace std;
class Singleton {
public:
  static Singleton &getInstance() { return uniqueInstance; }

  int get() { return val; }

private:
  Singleton() : val(0) {}
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  static Singleton uniqueInstance;
  int val;
};
Singleton Singleton::uniqueInstance;

int main() {
  Singleton::getInstance();
  auto start = chrono::steady_clock::now();
  for (int i = 0; i < 1e5; i++)
    Singleton::getInstance().get();
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

  start = chrono::steady_clock::now();
  auto &instance = Singleton::getInstance();
  for (int i = 0; i < 1e5; i++)
    instance.get();
  end = chrono::steady_clock::now();
  diff = end - start;
  cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}