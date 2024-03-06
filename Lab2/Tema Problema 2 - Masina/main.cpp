#include "Masina.h"

Masina balaur;

int main() {
	balaur.setFirma("BMW Seria 5");
	balaur.setKilometraj(3000000);
	balaur.setRezervor(60);
	balaur.setConsum(13);

	std::cout << balaur.getFirma() << "\n";
	
	std::cout << balaur.getRezervor() << "\n";
	balaur.Bisnitar(3500);
	std::cout << balaur.getKilometraj() << "\n";
	if(balaur.Cursa(1000))
		std::cout << balaur.getRezervor() << "\n";
	if (balaur.Cursa(300))
		std::cout << balaur.getRezervor() << "\n";

	return 0;
}