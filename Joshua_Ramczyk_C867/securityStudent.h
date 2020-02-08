#pragma once
#include "student.h"

class SecurityStudent : public Student{

private:

	Degree degProg = SECURITY;

public:
	
	Degree getDegreeProgram();

	SecurityStudent();
	SecurityStudent(string, string, string, string, int, int*, Degree);	
	
	void Print();

};