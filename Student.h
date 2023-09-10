#ifndef STUDENT_H
#define STUDENT_H
#include "Degree.h"

class Student {
	public:
		//Constructor with no parameters
		Student();
		// Constructor with all parameters
		Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);
		//Destructor
		~Student();

		//getter functions
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int *getDaysToComplete();
		DegreeProgram getDegreeProgram();

		//setter functions
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDaysToComplete(int daysToComplete[]);
		void setDegreeProgram(DegreeProgram degreeProgram);

		//prints all student data for an object
		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int daysToComplete[3];
		DegreeProgram degreeProgram;
};

#endif