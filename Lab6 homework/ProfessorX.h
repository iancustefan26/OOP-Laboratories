#pragma once
#ifndef PROFESSORX_H
#define PROFESSORX_H
#include "Bubbles.h"
#include "Buttercup.h"
#include "Blossom.h"
#include <iostream>

struct Girls {
	PowerPuff* girl;
	bool alive = 1;
};

class ProffesorX {
private:
	int sugar;
	int spice;
	int everything_nice;
	int number_of_girls;
	Girls* girls[20];
	int alive;
private:
	int min(int a, int b, int c) {
		if (b < a)
			a = b;
		if (a < c)
			return a;
		return c;
	}
	PowerPuff* newGirl() {
		int x = rand() % 3;
		//rand(x) from 1 to 3
		switch (x) {
		case 1:
			return new Bubbles();
			break;
		case 2:
			return new Blossom();
			break;
		default:
			return new Buttercup();
			break;
		}
	}
	void createPowerPuffs() {
		number_of_girls = min(sugar, spice, everything_nice);

		for (int i = 0; i < number_of_girls; ++i)
			girls[i] = new Girls, girls[i]->girl = newGirl(), girls[i]->alive = true;
		alive = number_of_girls;
	}
public:
	ProffesorX(const char* shop_list[], int size) {
		sugar = 0;
		spice = 0;
		everything_nice = 0;
		number_of_girls = 0;
		for(int i = 0; i < size - 1; ++i)
			if (strcmp(shop_list[i], "sugar") == 0) 
				sugar++;
			else if (strcmp(shop_list[i], "spice") == 0)
				spice++;
			else
				everything_nice++;
		createPowerPuffs();
	}
	void killPowerPuff(int i) {
		girls[i]->alive = 0;
	}
	void dealDamage(int i, int damage) {
		girls[i]->girl->lowerHealth(damage);
	}
	int getDamage(int i) const{
		return girls[i]->girl->getDamage();
	}
	int powerpuffs_still_alive() const{
		return alive;
	}
	bool powerpuff_still_alive(int i) const{
		return girls[i]->girl->getHealth() > 0;
	}
	~ProffesorX() {
		for (int i = 0; i < number_of_girls; ++i)
			delete girls[i];
	}
};

#endif