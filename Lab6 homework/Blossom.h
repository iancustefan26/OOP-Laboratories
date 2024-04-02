#pragma once
#ifndef BLOSSOM_H
#define BLOSSOM_H
#include "PowerPuff.h"

class Blossom : public PowerPuff {
private:

public:
	Blossom() : PowerPuff(100.f, 78.3f, "Blossom") {};
	float getHealth() const override{
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
