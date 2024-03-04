#ifndef GLOBALFUNC_H
#define GLOBALFUNC_H
#include "Student.h"

int compareNames(Student *s, Student *t);

int compareMath(Student* s, Student* t);
int compareHist(Student* s, Student* t);
int compareEngl(Student* s, Student* t);

int compareAverage(Student* s, Student* t);


#endif // !GLOBALFUNC_H
