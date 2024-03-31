#include "Circuit.h"
#pragma warning(disable: 4996)

Circuit::Circuit() {
	number_of_cars = 0;
	current_weather = Weather::Sunny;
	lenght = 0;
	number_of_losers = 0;
	times = nullptr;
}

void Circuit::SetLenght(int lenght) {
	this->lenght = lenght;
}

void Circuit::SetWeather(Weather weather) {
	this->current_weather = weather;
}

void Circuit::AddCar(Car* car) {
	cars[number_of_cars++] = car;
}

void Circuit::Race() {
	times = new Times[number_of_cars + 1];
	for(int i = 0; i < number_of_cars; ++i)
		if (cars[i]->getFuelTank() < float(lenght / 100 * cars[i]->getFuelConsumption())) {
			char* temp = *losers + number_of_losers;
			temp = new char[strlen(cars[i]->getName()) + 1];
			strcpy(temp, cars[i]->getName());
			number_of_losers++;
		}
		else {
			times[i].name = new char[strlen(cars[i]->getName()) + 1];
			strcpy(times[i].name, cars[i]->getName());
			times[i].time = float(lenght) / cars[i]->getAvgSpeed(current_weather);
		}
}

void Circuit::ShowFinalRanks() {
	std::cout << "Race Ranks: \n-------------\n";
	for (int i = 0; i < number_of_cars; ++i)
		if (times[i].time)
			std::cout << i + 1 << ". " << times[i].name
			<< " Has Finished #" << times[i].place + 1<< " in "
			<< std::fixed << std::setprecision(2) << times[i].time << "h\n";
}

void Circuit::ShowWhoDidNotFinish() {
	std::cout << "\n-------------\nCars which remained out of fuel during the race: \n";
	for (int i = 0; i < number_of_losers; ++i)
		std::cout << *losers[i] << "\n";
}

Circuit::~Circuit() {
	//delete cars;
	delete[] times;
	delete[] losers;
}