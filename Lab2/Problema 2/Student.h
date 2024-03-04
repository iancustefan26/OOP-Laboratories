#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
	float mathGrade, englGrade, histGrade;
	const char* name;;
	float average = calcAverage();
public:
	void setName(const char *name);
	const char* getName();
	void setMathGrade(float grade);
	float getMathGrade();
	void setEnglGrade(float grade);
	float getEnglGrade();
	void setHistGrade(float grade);
	float getHistGrade();
	float calcAverage();
};

#endif