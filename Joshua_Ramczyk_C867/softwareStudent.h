#pragma once
#include "student.h"

class SoftwareStudent : public Student {

private:

	Degree degProg = SOFTWARE;

public:

	SoftwareStudent();
	SoftwareStudent(string, string, string, string, int, int*, Degree);
	Degree getDegreeProgram();
	void Print();

};