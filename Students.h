#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <array>
using namespace std;

class Students
{
    public:
    static const int ARRAY_SIZE = 3;

    Students();

    Students(
        string studentID,
        string firstName,
        string lastName,
        string email,
        int age,
        int numbersOfDaysToCompleteeachCourse[ARRAY_SIZE],
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
    void setNumbersOfDaysToCompleteCourse(int numsOfDaysToCompleteeachCourse[ARRAY_SIZE]);
    int* getNumbersOfDaysToCompleteCourse();

    // age getters
    void setDegree(string degree);
    string getDegree();

    void print();

    private:
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int numbersOfDaysToCompleteeachCourse[ARRAY_SIZE];
        string degree;
};
#endif