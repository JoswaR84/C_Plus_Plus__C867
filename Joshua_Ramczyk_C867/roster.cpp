/*************************
* Joshua Ramczyk - C867  *
**************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include "roster.h"
using namespace std;

Roster::Roster(){}

int main(){	

	cout << "Class: Scripting and Programming - Applications - C867" << endl
		<< "Language: C++" << endl
		<< "Student ID: #000949874" << endl
		<< "Student Name: Joshua Ramczyk" << endl << endl;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Joshua,Ramczyk,jramczy@wgu.edu,35,20,20,20,SOFTWARE"	
	};
	
	//Instantiate Roster & Degree
	Roster roster;
	Degree degree;	

	for (int i=0; i<sizeof(studentData) / sizeof(studentData[i]); i++){
		string input = studentData[i];		
		istringstream ss(input);
		string delimiter;
		string tempArray[9];
		int delimterCounter = 0;
		while (getline(ss, delimiter, ',')) {
			tempArray[delimterCounter] = delimiter;
			delimterCounter++;
		}
		if (tempArray[8] == "SECURITY") {
			degree = Degree::SECURITY;
		}
		else if (tempArray[8] == "SOFTWARE") {
			degree = Degree::SOFTWARE;
		}
		else if (tempArray[8] == "NETWORK") {
			degree = Degree::NETWORKING;
		}
		roster.Add(tempArray[0], tempArray[1], tempArray[2], 
				   tempArray[3], stoi(tempArray[4]), stoi(tempArray[5]),
				   stoi(tempArray[6]), stoi(tempArray[7]), degree);

	}
	
	roster.PrintAll();
	roster.PrintInvalidEmails();
	for (int i=0; i<5; i++){roster.PrintAverageDaysInCourse(roster.getClassRosterArray()[i]->getStudentID());}
	cout << endl;
	roster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;
	roster.Remove("A3");
	roster.Remove("A3");
	system("pause");

}

void Roster::Add(string ID, string First, string Last, string EmailAddress, int setAge, int numDays0, int numDays1, int numDays2, Degree degProg)
{
	int avgNumofDays[3] = { numDays0, numDays1, numDays2 };
	if (degProg == NETWORKING) {
		classRosterArray[globalIndex] = new NetworkStudent(ID, First, Last, EmailAddress, setAge, avgNumofDays, degProg);
	}
	else if (degProg == SECURITY) {
		classRosterArray[globalIndex] = new SecurityStudent(ID, First, Last, EmailAddress, setAge, avgNumofDays, degProg);
	}
	else if (degProg == SOFTWARE) {
		classRosterArray[globalIndex] = new SoftwareStudent(ID, First, Last, EmailAddress, setAge, avgNumofDays, degProg);
	}
	globalIndex = globalIndex + 1;
}

void Roster::Remove(string studentID) {
	bool removeStudent = false;	
	for (int i=0; i<sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && (*classRosterArray[i]).getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			removeStudent = true;
			break;
		}
	}
	if (removeStudent == false) {
		cout << "ERROR! The following Student ID: " << studentID << " was not found. Deleting ID..." << endl;
	}
}

void Roster::PrintAll() {
	for (int i=0; i<5; i++) {
		(*classRosterArray[i]).Print();
	}
	cout << endl;
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	float averageDaysInCourse = 0;
	int minVal = 3;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			int* daysInCourse = classRosterArray[i]->getNumOfDays();
			for (int x = 0; x < minVal; x++) {
				averageDaysInCourse += daysInCourse[x];
			}
			cout << "Student ID " << classRosterArray[i]->getStudentID() << " has an average of " << (averageDaysInCourse / minVal) << " days to complete 3 courses." << endl;
			break;
		}
	}
}

void Roster::PrintInvalidEmails() {

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {
		string invalidEmail = classRosterArray[i]->getEmailAddress();
		int npos = -1;
		if ((invalidEmail.find("@") == npos) || (invalidEmail.find(".") == npos) || !(invalidEmail.find(" ") == npos)) {
			cout << invalidEmail << " is an invalid email" << endl;
		}
	}
	cout << endl;
}

void Roster::PrintByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}

Student** Roster::getClassRosterArray(){return classRosterArray;}
Roster::~Roster() {}