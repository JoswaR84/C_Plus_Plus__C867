#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent():Student(){}

NetworkStudent::NetworkStudent(string ID, string First, string Last, string emailAddress, int setAge, int* numDays, Degree studentDegree)
	:Student(ID, First, Last, emailAddress, setAge, numDays){
	degProg = studentDegree;
}

Degree NetworkStudent::getDegreeProgram(){
	return degProg;
}

void NetworkStudent::Print(){
	cout << getStudentID();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Age: " << getAge();
	cout << "\t" << "daysInCourse: {"; cout << getNumOfDays()[0] << ", " << getNumOfDays()[1] << ", " << getNumOfDays()[2] << "}";
	cout << "\t Degree Program:" << DegreeStrings[degProg];
	cout << endl;
}