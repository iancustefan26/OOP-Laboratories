#ifndef RANGEROVER_H
#define RANGEROVER_H
#include "car.h"

class RangeRover : public Car {
private:

public:
	RangeRover() : Car("RangeRover", 90, 17.0f) {};

	int getAvgSpeed(Weather weather) const override;

	virtual ~RangeRover() {
		delete[] name;
	}
};


#endif
