#ifndef BMW_H
#define BMW_H
#include "car.h"

class BMW : public Car {
private:

public:
	BMW() : Car("BMW", 80, 15.0f) {};

	int getAvgSpeed(Weather weather) const override;

	virtual ~BMW() {
		delete[] name;
	}
};


#endif
