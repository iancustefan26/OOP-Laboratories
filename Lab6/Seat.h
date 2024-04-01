#ifndef SEAT_H
#define SEAT_H
#include "car.h"

class Seat : public Car {
private:

public:
	Seat() : Car("Seat", 40, 8.7f) {};

	int getAvgSpeed(Weather weather) const override;

	virtual ~Seat() {
		delete[] name;
	}
};


#endif
