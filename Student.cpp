#include <iostream>
using namespace std;

#include "Student.h"


//Default constructor for the cration of the student array in the Roster.h file
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName =  "";
    this->email = "";
    this-> age = 0;
    this->daysToComplete[0] = 0;
    this->daysToComplete[1] = 0;
    this->daysToComplete[2] = 0;
    this->degreeProgram = SECURITY;
}

/*
Constructor for the Student class that includes all of the parameters from the table: student ID,
first name, last name, email address, age, array of number of days to complete each course, degree program.
*/
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName =  lastName;
    this->email = email;
    this-> age = age;
    this->daysToComplete[0] = daysToComplete[0];
    this->daysToComplete[1] = daysToComplete[1];
    this->daysToComplete[2] = daysToComplete[2];
    this->degreeProgram = degreeProgram;
}

//Destructor of student class
Student::~Student() {}

//Returns the student's ID
string Student::getStudentID() { return this->studentID; }

//Returns the student's first name
string Student::getFirstName() { return this->firstName; }

//Returns the student's last name
string Student::getLastName() { return this->lastName; }

//Returns the student's email
string Student::getEmail() { return this->email; }

//Returns the student's age
int Student::getAge() { return this->age; }

//Returns the number of days it took for the student to complete three courses
int *Student::getDaysToComplete() { return daysToComplete; }

//Returns the student's degree program
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Sets the value of the student's ID
void Student::setStudentID(string studentID) { this->studentID = studentID; }

//Sets the value of the student's first name
void Student::setFirstName(string firstName) { this->firstName = firstName; }

//Sets the value of the student's last name
void Student::setLastName(string lastName) { this->lastName = lastName; }

//Sets the value of the student's email
void Student::setEmail(string email) { this->email = email; }

//Sets the value of the student's age
void Student::setAge(int age) { this->age = age; }

//Sets the value for the number of days it took for the student to complete three courses
void Student::setDaysToComplete(int daysToComplete[]) { 
    this->daysToComplete[0] = daysToComplete[0];
    this->daysToComplete[1] = daysToComplete[1];
    this->daysToComplete[2] = daysToComplete[2];
    }

//Sets the value of the student's degree program
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//Print all sudent data
void Student::print() {
    cout << "Student ID: " << studentID << "\t"
    << "First Name: " << firstName << "\t"
    << "Last Name: " << lastName << "\t"
    << "Email: "<< email << "\t"
    << "Age: " << age << "\t\t" 
    << "daysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}\t" 
    << "Degree Program: " << degreeProgramStrings[degreeProgram] << endl;
}
