#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include "Students.h"
#include "Degree.h"
#include "Rooster.h"


using namespace std;

Rooster::Rooster() {};

Rooster::~Rooster() {};

void Rooster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	Students* student = new Students();
	string degree;

	int numbersOfDaysToCompleteCourse[3] = { daysInCourse1 , daysInCourse2, daysInCourse3};
	student -> setStudentID(studentID);
	student -> setFirstName(firstName);
	student -> setLastName(lastName);
	student -> setEmail(emailAddress);
	student -> setAge(age);
	student -> setNumbersOfDaysToCompleteCourse(numbersOfDaysToCompleteCourse);

	map<DegreeProgram, string> DegreeProgramMap = { 
		{DegreeProgram::SECURITY , "SECURITY"},
		{DegreeProgram::NETWORK , "NETWORK"},
		{DegreeProgram::SOFTWARE , "SOFTWARE"}
	};
	degree = DegreeProgramMap[degreeProgram];

	student -> setDegree(degree);

	this-> students.push_back(student);
};

void Rooster::remove(string studentID) {

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getStudentID() == studentID) {
			cout << "Deleting Student with StudentID : " << students[i]->getStudentID() << endl;
			students.erase(students.begin() + i);
			return;
		};

	};
	cout << "Student with ID: " << studentID << " was not found" << endl;
};

void Rooster::printAll() {
	for (int i = 0; i < students.size(); i++)
	{
		cout << "|-----------------------------------------------|" << endl;
		cout << "|                 STUDENT " << i + 1 << "                     |" << endl;
		cout << "|-----------------------------------------------|" << endl;

		students[i]-> print();
		cout << " " << endl;
	}
};

void Rooster::printAverageDaysInCourse(string studentID) {
	int temp = 0;

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getStudentID() == studentID) {
			for (int j = 0; j < Students::ARRAY_SIZE; j++) {
				temp = temp + students[i]->getNumbersOfDaysToCompleteCourse()[j];
			};
			cout << "Average Days In Course For Student with Sutend ID " << studentID << " " << temp / Students::ARRAY_SIZE << endl;
			cout << " " << endl;
			return;
		};

	};

	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

};

void Rooster::printInvalidEmails() {
	cout << " " << endl;
	cout << "*****Rooster by Invalid Emails"  << "*********" << endl;
	cout << " " << endl;
	for (int i = 0; i < students.size(); i++)
	{	
		string email = students[i]->getEmail();
		
		if (email.find('.') == string::npos || email.find("@") == string::npos || email.find(' ') != string::npos) {
			cout << students[i]->getEmail() << endl; 
		}
		

	}
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
};

void Rooster::printByDegreeProgram(DegreeProgram degreeProgram) {
	map<DegreeProgram, string> DegreeProgramMap = {
		{DegreeProgram::SECURITY , "SECURITY"},
		{DegreeProgram::NETWORK , "NETWORK"},
		{DegreeProgram::SOFTWARE , "SOFTWARE"}
	};
	string degree = DegreeProgramMap[degreeProgram];
	cout << " " << endl;
	cout << "*****Rooster by " << degree << "*********"<<endl;
	cout << " " << endl;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getDegree() == degree) {
			students[i]->print();
			cout << " " << endl;
		}

	}
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

};