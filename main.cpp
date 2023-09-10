#include <iostream>
using namespace std;

#include "Roster.h"

int main() {
    //Required information of class and student
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl << "Programming Language: C++" << endl << "WGU Student ID: 011001250" 
    << endl << "Author: Chase Gruet" << endl << endl;

    //All the student data from the student data table
    const string studentData[5] = {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chase,Gruet,cgruet1@wgu.edu\t,26,24,38,43,SOFTWARE"};

    const int rosterSize = 5;
    //Create roster with default constructor and then parse data to fill it in
    Roster roster;
    for (int i = 0; i < rosterSize; i++) {
        roster.parseData(studentData[i]);
    }

    //All required function from problem statement for the main()
    roster.printAll();
    cout << endl;
    roster.printInvalidEmails();
    cout << endl;
    
    
    for (int i = 0; i < rosterSize; i++) {
        roster.printAverageDaysInCourse(roster.getStudentID(i));
    }
    cout << endl;
    
    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    roster.remove("A3");
    cout << endl;
    roster.printAll();
    cout << endl;
    roster.remove("A3");
    cout << endl;
    
    return 0;
}