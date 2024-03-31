#include "BMW.h"

int BMW::getAvgSpeed(Weather weather) const{
	switch (weather) {
		case Weather::Rain:
			return 130;
		case Weather::Sunny:
			return 170;
		case Weather::Snow:
			return 90;
	}
}

