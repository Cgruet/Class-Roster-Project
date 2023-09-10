#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"

class Roster {
	public:
		// Destructor
		~Roster();

		void parseData(string individualStudentData);
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID); 
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		string getStudentID(int i);

	private:
		int currentArrayIndex = 0;
		const static int rosterSize = 5;		
		Student *classRosterArray[rosterSize];
		
};

#endif