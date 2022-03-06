#include <iostream>
#include <string>
#include <array>
#include "Students.h"

using namespace std;

Students::Students(){};

Students::Students(string studentID, string firstName, string lastName, string email, int age, int numbersOfDaysToCompleteeachCourse[3], string degree)
{
    this-> studentID = studentID; 
    this-> firstName = firstName; 
    this-> lastName = lastName; 
    this-> email = email; 
    this-> age = age; 
    this-> numbersOfDaysToCompleteeachCourse[0] =  numbersOfDaysToCompleteeachCourse[0];
    this-> numbersOfDaysToCompleteeachCourse[1] =  numbersOfDaysToCompleteeachCourse[1];
    this-> numbersOfDaysToCompleteeachCourse[2] =  numbersOfDaysToCompleteeachCourse[2];
    this-> degree = degree; 
};

Students::~Students()
{
    cout<< "students " << firstName << " is been destroyed" << endl;
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
string getFirstName()
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

// numbersOfDaysToCompleteeachCourse getters and setters
void Students::setNumbersOfDaysToCompleteeachCourse(int value, int index)
{
    
        this->numbersOfDaysToCompleteeachCourse[index] = value; 
};

// array <array int> Students::getNumbersOfDaysToCompleteeachCourse()
// {
//     return this->numbersOfDaysToCompleteeachCourse;
// }

// age getters and setters
void Students::setDegree(int age)
{
    this->age = age;
};
string Students::getDegree()
{
    return degree;
};

template <typename ValueType>
void Students::print(ValueType studentData)
{
    cout << studentData << endl;
};
