#pragma once
#ifndef BUBBLES_H
#define BUBBLES_H
#include "PowerPuff.h"

class Bubbles : public PowerPuff {
private:

public:
	Bubbles() : PowerPuff(100.f, 59.31f, "Bubbles") {};
	float getHealth() const override {
		return this->health;
	}
	float getDamage() const override {
		return this->damage;
	}
	void lowerHealth(unsigned int damage) {
		this->health -= damage;
	}
	~Bubbles() {
		delete[] name;
	}
};

#endif // !
#pragma once
#pragma once
