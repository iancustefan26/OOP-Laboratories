#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "weather.h"
#pragma warning(disable: 4996)

class Car {
protected:
	char* name;
private:
	unsigned int tank;
	float fuel_consumption;
public:
	Car(const char* name, unsigned int liters, float cons)
		: tank(liters), fuel_consumption(cons){
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	virtual int getAvgSpeed(Weather weather) const = 0;

	const char* getName() const {
		return this->name;
	}
	float getFuelConsumption() const {
		return fuel_consumption;
	}
	int getFuelTank() const {
		return tank;
	}
	virtual ~Car() {
		delete[] name;
	}
};

#endif