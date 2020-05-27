#include<iostream>
using namespace std;

#include "Beverages.h"


int main(){
	beverage* coffee = new espresso();
	cout<<coffee->getDescription()<<endl;
	cout<<coffee->getCost()<<endl;

	coffee = new mocha(coffee);
	cout<<coffee->getDescription()<<endl;
	cout<<coffee->getCost()<<endl;

	coffee = new soy(coffee);
	coffee = new mocha(coffee);
	cout<<coffee->getDescription()<<endl;
	cout<<coffee->getCost()<<endl;

	return 0;
}