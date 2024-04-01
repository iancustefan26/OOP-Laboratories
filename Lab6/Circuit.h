#ifndef CIRCUIT_h
#define CIRCUIT_h
#include "car.h"
#include "weather.h"
#include <iomanip>

struct Times {
	float time = 0;
	char* name;
	int place = 0;
};

class Circuit {
private:
	Weather current_weather;
	int lenght;
	int number_of_cars;
	Car* cars[20] = {nullptr};
	Times* times; //in hours
	char* losers[20] = { nullptr };
	int number_of_losers;

	void Sort();
public:
	Circuit();
	void SetLenght(int lenght);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	~Circuit();
};

#endif