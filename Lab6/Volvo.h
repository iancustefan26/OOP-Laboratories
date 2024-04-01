#ifndef VOLVO_H
#define VOLVO_H
#include "car.h"

class Volvo : public Car {
private:

public:
	Volvo() : Car("Volvo", 100, 11.0f) {};

	int getAvgSpeed(Weather weather) const override;

	virtual ~Volvo() {
		delete[] name;
	}
};


#endif