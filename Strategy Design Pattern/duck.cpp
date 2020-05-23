#include<iostream>
#include "flyingBehavior.h"
#include "quackingBehavior.h"

using namespace std;

// interface that all duck classes implements.
class duck{
private:
	// favour composition over inheritence
	quackingBehavior* quackBehavior;
	flyingBehavior* flyBehavior;

public:
	virtual void display() = 0;

	void performFly(){
		flyBehavior->fly();
	}

	void performQuack(){
		quackBehavior->sound();
	}

	void setQuackBehavior(quackingBehavior* newQuackBehavior){
		quackBehavior = newQuackBehavior;
	}

	void setFlyBehavior(flyingBehavior* newFlyBehavior){
		flyBehavior = newFlyBehavior;
	}

	void performSwim(){
		cout<<"Every duck can swim"<<endl;
	}
};

class mallardDuck : public duck{
public:
	mallardDuck(){
		setQuackBehavior(new quack());
		setFlyBehavior(new flyWithWings());
	}

	void display(){
		cout<<"Hey, I'm Mallard Duck"<<endl;
	}
};

int main(){
	mallardDuck *obj = new mallardDuck();
	obj->performFly();
}
