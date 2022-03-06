
#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <array>
using namespace std;

class Students
{
public:
    //constructors
    Students();
    Students(string studentID,
    string firstName,
    string lastName,
    string email,
    int age,
    array<int,3> numbersOfDaysToCompleteeachCourse,
    string degree);

    //deconstructors
    ~Students();

    // stundentID getters and setters
    void setStudentID(string studentID);
    string getStudentID();

    // firstName getters and setters
    void setFirstName(string firstName);
    string getFirstName();
 
    // lastName getters
    void setLastName(string lastName);
    string getLastName();

    // email getters
    void setEmail(string email);
    string getEmail();

    // age getters
    void setAge(int age);
    int getAge();

    // numbersOfDaysToCompleteeachCourse getters
    void setNumbersOfDaysToCompleteeachCourse(int value, int index);

    // int * getNumbersOfDaysToCompleteeachCourse();

    // age getters
    void setDegree(int age);
    string getDegree();

    template <typename ValueType> void print(ValueType studentData);

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    array <int,3> numbersOfDaysToCompleteeachCourse;
    string degree;
};
#endif