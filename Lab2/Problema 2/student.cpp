#include <iostream>
#include "Student.h"

float Student::calcAverage() {
	this->average = (this->englGrade + this->histGrade + this->mathGrade) / 3.0f;
	return this->average;
}



float Student::getEnglGrade() {
	return this->englGrade;
}

float Student::getMathGrade() {
	return this->mathGrade;
}

float Student::getHistGrade() {
	return this->histGrade;
}

void Student::setName(const char* myName) {
	this->name = myName;
}

const char* Student::getName() {
	return this->name;
}

void Student::setMathGrade(const float grade) {
	this->mathGrade = grade;
}

void Student::setHistGrade(const float grade) {
	this->histGrade = grade;
}

void Student::setEnglGrade(const float grade) {
	this->englGrade = grade;
}