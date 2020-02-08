#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent():Student(){}

SecurityStudent::SecurityStudent(string ID, string First, string Last, string emailAddress, int setAge, int* numDays, Degree studentDegree)
	: Student(ID, First, Last, emailAddress, setAge, numDays){
	degProg = studentDegree;
}

Degree SecurityStudent::getDegreeProgram(){
	return degProg;
}

void SecurityStudent::Print(){
	cout << getStudentID();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Age: " << getAge();
	cout << "\t" << "daysInCourse: {"; cout << getNumOfDays()[0] << ", " << getNumOfDays()[1] << ", " << getNumOfDays()[2] << "}";
	cout << "\t Degree Program:" << DegreeStrings[degProg];
	cout << endl;
}