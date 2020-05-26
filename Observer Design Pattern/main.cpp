#include<iostream>
using namespace std;

#include "Observers.h"

int main(){
	subject* weather = new weatherData();

	//adding random observer
	observer* random = new randomDisplay(weather);
	weather->setMeasurements(20, 30, 40);

	// adding two new observers
	observer* currentWeather = new currentWeatherDisplay(weather);
	observer* currentCondition = new currentConditionDisplay(weather);

	// removing random observer
	weather->removeObserver(random);
	
	weather->setMeasurements(50, 80, 90);
	return 0;
}