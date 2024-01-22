#include <iostream>
using namespace std;

#include "Subject.h"

// different implementation of observers extending observer interface

class currentConditionDisplay : public observer {
private:
  float temprature, pressure;
  subject *weather;

public:
  currentConditionDisplay(subject *weather) {
    this->weather = weather;
    weather->addObserver(this);
  }

  void update(float temprature, float pressure, float humidity) {
    this->temprature = temprature;
    this->pressure = pressure;
    display();
  }

  void display() {
    cout << "currentConditionDisplay, temprature and pressure is " << temprature
         << " " << pressure << endl;
  }
};

class currentWeatherDisplay : public observer {
private:
  float temprature, pressure, humidity;
  subject *weather;

public:
  currentWeatherDisplay(subject *weather) {
    this->weather = weather;
    weather->addObserver(this);
  }

  void update(float temprature, float pressure, float humidity) {
    this->temprature = temprature;
    this->pressure = pressure;
    this->humidity = humidity;
    display();
  }

  void display() {
    cout << "Current Weather Display" << endl
         << "Temprature " << temprature << endl;
    cout << "Pressure " << pressure << endl;
    cout << "humidity " << humidity << endl;
  }
};

class randomDisplay : public observer {
private:
  float temprature, humidity;
  subject *weather;

public:
  randomDisplay(subject *weather) {
    this->weather = weather;
    weather->addObserver(this);
  }

  void update(float temprature, float pressure, float humidity) {
    this->temprature = temprature;
    this->humidity = humidity;
    display();
  }

  void display() {
    cout << "Random Display, temprature and humidity is " << temprature << " "
         << humidity << endl;
  }
};