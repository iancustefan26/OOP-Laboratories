#ifndef MASINA_H
#define MASINA_H

#include <iostream>
#include <cstring>

class Masina {
	private:
		char* firma = new char[40];
		int rezevor; //in litri
		float consum; // litri / 100km
		int kilometri;
	public:
		bool setKilometraj(int k);
		bool setFirma(const char *name);
		bool setRezervor(int litri);
		bool setConsum(float consum);
		char* getFirma();
		int getRezervor();
		float getConsum();
		int getKilometraj();

		void Bisnitar(int cati_dau_inapoi);
		bool Cursa(int kilometri);
};

#endif // !MASINA_H
