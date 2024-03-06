
#include "Masina.h"

bool Masina::setFirma(const char* nume) {
	if (!strcpy_s(this -> firma, 40, nume))
		return true;
	return false;
}

bool Masina::setConsum(float consum) {
	if (this->consum = consum)
		return 1;
	return false;
}

bool Masina::setRezervor(int litri) {
	if (rezevor = litri)
		return true;
	return false;
}

float Masina::getConsum(){
	return this->consum;
}

int Masina::getRezervor() {
	return this->rezevor;
}

char* Masina::getFirma() {
	return this->firma;
}

bool Masina::setKilometraj(int k) {
	if (this -> kilometri = k)
		return true;
	return false;
}

int Masina::getKilometraj() {
	return this->kilometri;
}

void Masina::Bisnitar(int cati_dau_inapoi){
	this->kilometri -= cati_dau_inapoi;
}

bool Masina::Cursa(int kilometri) {
	int calcul = kilometri / 100 * consum; //litri
	if (rezevor - calcul < 0) {
		std::cout << "N-ai destula benzina\n";
		return false;
	}

	rezevor -= calcul;
	this->kilometri += kilometri;

	return true;
}