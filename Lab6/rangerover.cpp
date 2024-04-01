#include "RangeRover.h"

int RangeRover::getAvgSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 80;
	case Weather::Sunny:
		return 141;
	case Weather::Snow:
		return 77;
	}
}

