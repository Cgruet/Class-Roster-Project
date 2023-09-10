#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "Roster.h"

//Parse the student data to add a student object to the student roster array
void Roster::parseData(string individualStudentData) {	
	string studentInfo[9];
	int start = 0;
	int end;
	
	//Loop to parse studentData
	for (int i = 0; i < 8; i++) {
		end = individualStudentData.find(",", start);
		studentInfo[i] = individualStudentData.substr(start, end - start);
		start = end + 1;		
	}
	studentInfo[8] = individualStudentData.substr(start, individualStudentData.length());

	//if statements to determine the enum degree program value
	enum DegreeProgram degreeProgram;
	if (studentInfo[8] == "SECURITY") {
		degreeProgram = SECURITY;
	} else if (studentInfo[8] == "NETWORK") {
		degreeProgram = NETWORK;
	} else {
		degreeProgram = SOFTWARE;
	}
		
	//Add student object to the roster array
	add(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], stoi(studentInfo[4]), stoi(studentInfo[5]), stoi(studentInfo[6]), stoi(studentInfo[7]), degreeProgram);
	
	
}


//Add a new student to the roster with all of their information.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	//Create an array for the three values of the number of days to complete each course
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	//Create a new Sudent object
	Student student1(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);

	//Create a new array of one size bigger and fill with old pointers and new pointer
	classRosterArray[currentArrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
	currentArrayIndex++;
}

//Removes a student from the roster
void Roster::remove(string studentID) {
	bool isFound = false;
	for (int i = 0; i < Roster::currentArrayIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			isFound = true;
			
			// Changes the location of the remove student to the end and shrink the visible size of the roster
			if (i < currentArrayIndex - 1) {
				Student *temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[currentArrayIndex - 1];
				classRosterArray[currentArrayIndex - 1] = temp;
			}
			Roster::currentArrayIndex--;
		}
		
	}
	
	if (isFound) {
	cout << "The student with the ID: " << studentID << " has been removed from the roster." << endl; 
	}
	else {
		//Prints if no student in the current roster has this ID.
		cout << "Error: a student with this ID was not found." << endl;
	}
}

//Print all data for all students.
void Roster::printAll() {
	string degreeProgram;
	for (int i = 0; i < Roster::currentArrayIndex; i++) {
		classRosterArray[i]->print();		
	}
}

//Print the average of the days in course array for a student determined by thier ID.
void Roster::printAverageDaysInCourse(string studentID) {
	double average;
	for (int i = 0; i < Roster::currentArrayIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			average = classRosterArray[i]->getDaysToComplete()[0] + classRosterArray[i]->getDaysToComplete()[1] + classRosterArray[i]->getDaysToComplete()[2];
			cout << "Student " << studentID << " takes an average of " << average/3 << " day to finish three courses." << endl;
		}
	}
}

//Look for and print invalid email addresses based on the given parameters
void Roster::printInvalidEmails() {
	bool invalidEmails = false;
	for (int i = 0; i < Roster::currentArrayIndex; i++) {
		string email = classRosterArray[i]->getEmail();
		if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
			cout << "Invaid email addresses:" << endl;
			invalidEmails = true;
			break;
		}
	}
	if (invalidEmails) {
		for (int i = 0; i < Roster::currentArrayIndex; i++) {
			string email = classRosterArray[i]->getEmail();
			if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
				cout << email << endl;
			}
		}
	} else {
		cout << "There are no invalid email addresses." << endl;
	}	
}

//Print all student data that have a matching degree program as the parameter
 void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < Roster::currentArrayIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
 }

//Used to return each student ID in classRosterArray to iterate through classRosterArray in main()
string Roster::getStudentID(int i) {
	string ID = classRosterArray[i]->getStudentID();
	return ID;
}


//Destrucot
 Roster::~Roster() {
	cout << "Running destructor" << endl;
	for(int i = 0; i < rosterSize; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
 }