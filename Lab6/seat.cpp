#include "Seat.h"

int Seat::getAvgSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 68;
	case Weather::Sunny:
		return 112;
	case Weather::Snow:
		return 53;
	}
}

