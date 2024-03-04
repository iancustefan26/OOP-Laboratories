#include <iostream>
#include <string.h>
#include "GlobalFunc.h"

int compareAverage(Student* s, Student* t) {
	int retr = s->calcAverage() - t->calcAverage();
	if (retr > 0)
		return 1;
	else if (retr < 0)
		return -1;
	else return 0;
}

int compareNames(Student* s, Student* t){
	return strcmp(s->getName(), t->getName());
}

int compareEngl(Student* s, Student* t) {
	return (s->getEnglGrade() - t->getEnglGrade() > 0) ? 1 :
		(s->getEnglGrade() - t->getEnglGrade() < 0 ? -1 : 0);
}

int compareMath(Student* s, Student* t) {
	return (s->getMathGrade() - t->getMathGrade() > 0) ? 1 :
		(s->getMathGrade() - t->getMathGrade() < 0 ? -1 : 0);
}
int compareHist(Student* s, Student* t) {
	return (s->getHistGrade() - t->getHistGrade() > 0) ? 1 :
		(s->getHistGrade() - t->getHistGrade() < 0 ? -1 : 0);
}