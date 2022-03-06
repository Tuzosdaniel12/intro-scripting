#include <iostream>
#include <string>
#include <array>
#include <map>
#include "Students.h"

using namespace std;

const int Students::ARRAY_SIZE;

Students::Students() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;

    for (int i = 0; i < Students::ARRAY_SIZE; i++) {
        this->numbersOfDaysToCompleteeachCourse[i] = 0;
    };

    this->degree = "";
};

Students::Students(
    string studentID,
    string firstName,
    string lastName,
    string email,
    int age,
    int numbersOfDaysToCompleteeachCourse[Students::ARRAY_SIZE],
    string degree)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;

    for (int i = 0; i < Students::ARRAY_SIZE; i++) {
        this->numbersOfDaysToCompleteeachCourse[i] = numbersOfDaysToCompleteeachCourse[i];
    };

    this->degree = degree;
};

Students::~Students()
{
    cout << "students " << firstName << " is been destroyed" << endl;
};
// stundentID getters and setters
void Students::setStudentID(string studentID)
{
    this->studentID = studentID;
};
string Students::getStudentID()
{
    return studentID;
};

// firstName getters and setters
void Students::setFirstName(string firstName)
{
    this->firstName = firstName;
};
string Students::getFirstName()
{
    return firstName;
};

// lastName getters and setters
void Students::setLastName(string lastName)
{
    this->lastName = lastName;
};
string Students::getLastName()
{
    return lastName;
};

// email getters and setters
void Students::setEmail(string email)
{
    this->email = email;
};
string Students::getEmail()
{
    return email;
};

// age getters and setters
void Students::setAge(int age)
{
    this->age = age;
};
int Students::getAge()
{
    return age;
};

//numbersOfDaysToCompleteeachCourse getters and setters
void Students::setNumbersOfDaysToCompleteCourse(int numsOfDaysToCompleteeachCourse[Students::ARRAY_SIZE])
{
    for (int i = 0; i < Students::ARRAY_SIZE; i++) {
        this->numbersOfDaysToCompleteeachCourse[i] = numsOfDaysToCompleteeachCourse[i];
    };
};
   

int* Students::getNumbersOfDaysToCompleteCourse()
{
     return numbersOfDaysToCompleteeachCourse;
};

// age getters and setters
void Students::setDegree(string degree)
{
    this->degree = degree;
};
string Students::getDegree()
{
    return degree;
};

void Students::print()
{   
    string temp = "";
    for (int i = 0; i < Students::ARRAY_SIZE; i++) {
        temp = temp + to_string(getNumbersOfDaysToCompleteCourse()[i]) + ", ";
    };

    cout << " Student ID: "
        << getStudentID() << "    "
        << " First Name: "
        << getFirstName() << "    "
        << " Last Name: "
        << getLastName() << "    "
        << " Email: "
        << getEmail() << "    "
        << " Age: "
        << getAge() << "    "
        << " Days in Course: "
        << temp << "    "
        << " Degree Program: "
        << getDegree() << endl;
         
}
    
