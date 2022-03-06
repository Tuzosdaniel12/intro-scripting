#ifndef ROOSTER_H
#define ROOSTER_H

#include <string>
#include <vector>
#include "Students.h"
#include "Degree.h"

using namespace std;

class Rooster
{
public:

    Rooster();
    //deconstructors
    ~Rooster();
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

    vector<Students *> students;
};
#endif