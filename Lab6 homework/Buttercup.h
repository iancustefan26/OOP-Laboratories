#pragma once
#ifndef BUTTERCUP_H
#define BUTTERCUP_H
#include "PowerPuff.h"

class Buttercup : public PowerPuff {
private:

public:
	Buttercup() : PowerPuff(100.f, 63.3f, "Buttercup") {};
	float getHealth() const override {
		return this->health;
	}
	float getDamage() const override {
		return this->damage;
	}
	void lowerHealth(unsigned int damage) {
		this->health -= damage;
	}
};

#endif // !
#pragma once
