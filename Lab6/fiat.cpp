#include "Fiat.h"

int Fiat::getAvgSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 60;
	case Weather::Sunny:
		return 107;
	case Weather::Snow:
		return 50;
	}
}

