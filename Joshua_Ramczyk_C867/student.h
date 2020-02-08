#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student{

private:
	string	studentID;
	string	firstName;
	string	lastName;
	string	emailAddress;
	int		age;
	int		numOfDays[3];

public:
	//Constructors
	Student();
	Student(string ID, string First, string Last, string EmailAddress, int setAge, int* numDays);

	//Accessors - Getters
	string	getStudentID();
	string	getFirstName();
	string	getLastName();
	string	getEmailAddress();
	int		getAge();
	int		*getNumOfDays();
	virtual Degree getDegreeProgram();

	//Mutators - Setters
	void	setStudentID(string studentID);
	void	setFirstName(string firstName);
	void	setLastName(string lastName);
	void	setEmailAddress(string emailAddress);
	void	setAge(int age);
	void	setNumOfDays(int val1, int val2, int val3);
	virtual void setDegree(string degree);
	virtual void Print();

	//Destructor
	~Student();

};