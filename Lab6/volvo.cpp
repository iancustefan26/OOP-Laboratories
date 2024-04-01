#include "Volvo.h"

int Volvo::getAvgSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 90;
	case Weather::Sunny:
		return 137;
	case Weather::Snow:
		return 65;
	}
}

