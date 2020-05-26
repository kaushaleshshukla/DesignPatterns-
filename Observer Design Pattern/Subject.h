#include<bits/stdc++.h>
using namespace std;

#include "Observer.h"

// subject interface
class subject{
public:
	virtual void addObserver(observer* newObserver) = 0;
	virtual void removeObserver(observer* Observer) = 0;
	virtual void notifyObserver() = 0;
	virtual void setMeasurements(float temprature, float pressure, float humidity) = 0;
};

// weatherData subject implementation
class weatherData : public subject{
private:
	unordered_set<observer*> Observers;
	//weather variables
	float humidity, temprature, pressure;
	bool changed = false;
public:

	void addObserver(observer* newObserver){
		if(Observers.find(newObserver) == Observers.end())
			Observers.insert(newObserver);
	}

	void removeObserver(observer* Observer){
		if(Observers.find(Observer) != Observers.end())
			Observers.erase(Observer);
	}


	// push updates to observers
	void notifyObserver(){
		if(!changed)
			return;
		for(auto x:Observers){
			x->update(temprature, pressure, humidity);
		}
		changed = false;
	}

	// getter methods for pull request from observers

	float getTemprature(){
		return temprature;
	}

	float getPressure(){
		return pressure;
	}

	float getHumidity(){
		return humidity;
	}

	void setMeasurements(float temprature, float pressure, float humidity){
		this->temprature = temprature;
		this->pressure = pressure;
		this->humidity = humidity;
		changed = true;
		// notifying the observers about new change
		notifyObserver();
	}


};