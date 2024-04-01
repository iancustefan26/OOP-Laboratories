#ifndef FIAT_H
#define FIAT_H
#include "car.h"

class Fiat : public Car {
private:

public:
	Fiat() : Car("Fiat", 30, 8.0f) {};

	int getAvgSpeed(Weather weather) const override;

	virtual ~Fiat() {
		delete[] name;
	}
};


#endif
