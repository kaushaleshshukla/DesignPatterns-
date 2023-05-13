#include<iostream>
using namespace std;

// Traditional ways
class Singleton{
private:
    static Singleton* uniqueInstance;
    Singleton(){};
public:
    static Singleton* getInstance(){
        if(!uniqueInstance)
            uniqueInstance = new Singleton();
        return uniqueInstance;
    }
};


Singleton* Singleton::uniqueInstance = nullptr;

int main(){
    Singleton* instance = Singleton::getInstance();
    if(instance)
        cout<<"Unique Instance created";
    return 0;
}

/** Types of Singleton */
//1 - Static Singleton => The object has only static data or static data as well as static method (constructor can be deleted)

class Singleton {
public:
    Singleton() {};
    int get() { return value; }
private:
    static int val;
}

/** Some bad design **/
//1
#include<iostream>
class Singleton
{
  private:
    Singleton(){
      val = 5;
    }
  public:
    static Singleton getInstance()
    {
      static Singleton uniqueInstance;
      // if(uniqueInstance == nullptr)
      //   uniqueInstance = new Singleton();
      return uniqueInstance;
    }
    int val;
};

int main() {
  auto singleInstance = Singleton::getInstance();
  singleInstance.val = 7;
  std::cout<<singleInstance.val<<std::endl;
  std::cout<<Singleton::getInstance().val<<std::endl;
}

//2
#include<iostream>
class Singleton
{
  private:
    Singleton(){
      val = 5;
    }
  public:
    static Singleton& getInstance()
    {
      static Singleton uniqueInstance;
      // if(uniqueInstance == nullptr)
      //   uniqueInstance = new Singleton();
      return uniqueInstance;
    }
    int val;
};

int main() {
  auto singleInstance = Singleton::getInstance();
  singleInstance.val = 7;
  std::cout<<singleInstance.val<<std::endl;
  std::cout<<Singleton::getInstance().val<<std::endl;
}

//3
#include<iostream>

int n;
class Singleton
{
  private:
    Singleton(){
      std::cout<<"Singleton Instantiated"<<std::endl;
      val = 5;
    }
  public:
    static Singleton* getInstance()
    {
      static Singleton* uniqueInstance = new Singleton();
      return uniqueInstance;
    }
    int val;
};

int main() {
  auto singleInstance = Singleton::getInstance();
  std::cout<<singleInstance->val<<std::endl;
  auto singleInstance2 = *singleInstance;
  singleInstance2.val = 7;
  std::cout<<singleInstance->val<<std::endl;
  std::cout<<singleInstance2.val<<std::endl;
}

//4 - not safe for multi-threaded code

#include<iostream>

int n;
class Singleton
{
  private:
    Singleton(int num){
      std::cout<<"Singleton Instantiated"<<std::endl;
      val = num;
    }
  public:
    static Singleton* getInstance(int n)
    {
      static Singleton* uniqueInstance = nullptr;
       if(uniqueInstance == nullptr)
         uniqueInstance = new Singleton(n);
      return uniqueInstance;
    }
    int val;
};

int main() {
  std::cin>>n;
  auto singleInstance = Singleton::getInstance(n);
  std::cout<<singleInstance->val<<std::endl;
  std::cin>>n;
  auto singleInstance2 = Singleton::getInstance(n);
  std::cout<<singleInstance->val<<std::endl;
  std::cout<<singleInstance2->val<<std::endl;
}

/**Three types Singleton for multithreaded environment*/

//1) Synchronize whole getInstance() method 

class Singleton {
public:
    static Singleton* getInstance() {
        //lock
        if(uniqueInstance == nullptr) {
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
        //release lock
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton* uniqueInstance;
};

Singleton* Singleton::uniqueInstance = nullptr;

//2) Create instance Eagerly rather than lazily creation

class Singleton {
public:
    static Singleton& getInstance() {
        return uniqueInstance;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton uniqueInstance;
};

Singleton Singleton::uniqueInstance;

//3) Use double-check locking

class Singleton {
public:
    static Singleton* getInstance() {
        if(uniqueInstance == nullptr) {
            // lock
            if(uniqueInstance == nullptr)
                uniqueInstance = new Singleton();
            // release lock
        }
        return uniqueInstance;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton* uniqueInstance;
};

Singleton* Singleton::uniqueInstance = nullptr;


//Mayer's Singleton
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton uniqueInstance;
        return uniqueInstance;
    }

    int get(){
        return val;
    }

private:
    Singleton() : val(0) {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    int val;
};