#pragma once
#ifndef POWERPUFF_H
#define POWERPUFF_H
#include <iostream>
#pragma warning(disable: 4996)

class PowerPuff {
protected:
	float health;
	float damage;
	char* name;
public:
	PowerPuff(float health, float damage, const char* name)
		: health(health), damage(damage) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	virtual float getHealth() const = 0;
	virtual float getDamage() const = 0;
	virtual void lowerHealth(unsigned int damage) = 0;
	virtual ~PowerPuff() {
		delete[] name;
	}
};

#endif