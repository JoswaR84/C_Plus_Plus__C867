#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Empty Constructor
Student::Student(){

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->numOfDays[0] = 0;
	this->numOfDays[1] = 0;
	this->numOfDays[2] = 0;

}

//Full Constructor 
Student::Student(string StudentID, string First, string Last, string EmailAddress, int Age, int *numDays){

	this->studentID = StudentID;
	this->firstName = First;
	this->lastName = Last;
	this->emailAddress = EmailAddress;
	this->age = Age;
	this->numOfDays[0] = numDays[0];
	this->numOfDays[1] = numDays[1];
	this->numOfDays[2] = numDays[2];

}

// Accessors - Getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getNumOfDays()
{
	return numOfDays;
}

Degree Student::getDegreeProgram(){
	if (Degree::NETWORKING){
		return Degree::NETWORKING;
	}
	if (Degree::SECURITY) {
		return Degree::SECURITY;
	}
	if (Degree::SOFTWARE) {
		return Degree::SOFTWARE;
	}
}

// Mutators - Setters
void Student::setStudentID(string ID)
{
	this->studentID = ID;
}

void Student::setFirstName(string First)
{
	this->firstName = First;
}

void Student::setLastName(string Last)
{
	this->lastName = Last;
}

void Student::setEmailAddress(string EmailAddress)
{
	this->emailAddress = EmailAddress;
}

void Student::setAge(int setAge)
{
	this->age = setAge;
}

void Student::setNumOfDays(int numDays0, int numDays1, int numDays2){
	this->numOfDays[0] = numDays0;
	this->numOfDays[1] = numDays1;
	this->numOfDays[2] = numDays2;
}

void Student::setDegree(string degree)
{
	degree = degree;
}

void Student::Print(){}

//Destructor Call 
Student::~Student(){}