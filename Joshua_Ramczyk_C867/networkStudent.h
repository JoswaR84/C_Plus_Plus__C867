#pragma once
#include "student.h"

class NetworkStudent : public Student{

private:

	Degree degProg = NETWORKING;

public:
	
	NetworkStudent();
	NetworkStudent(string, string, string, string, int, int*, Degree);
	Degree getDegreeProgram();
	void Print();

};