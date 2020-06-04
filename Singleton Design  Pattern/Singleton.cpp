#include<iostream>
using namespace std;

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