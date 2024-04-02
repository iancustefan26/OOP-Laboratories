#pragma once
#ifndef MOJOJOJO_H
#define MOJOJOJO_H

class MojoJojo {
private:
	float health;
	float damage;
public:
	MojoJojo() : health(1000.23f), damage(12.34f) {};
	float getDamage() const {
		return damage;
	}
	float getHealth() const {
		return health;
	}
	void dealDamage(float damage) {
		this->health -= damage;
	}
};

#endif // !MOJOJOJO_H
