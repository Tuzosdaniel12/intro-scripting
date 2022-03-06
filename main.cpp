#include <iostream>
#include <string>
#include <array>
#include "Students.h"

using namespace std;

void printHeaders()
{
    const string courseTitle = " SCRIPTING AND PROGRAMMING - APPLICATIONS — C867 - ";
    const string language = "C++ - ";
    const string wguId = "004708060 - ";
    const string myName = "Daniel Soledad Gonzalez";
    const string header = courseTitle + language + wguId + myName;
    const int len = 7;

    for (int i = 0; i < len; i++)
    {
        if (i == 0 || i == 6)
        {
            cout << "|**************************************************************************************************|" << endl;
        }
        else if (i == 3)
        {
            cout << "|  " << header << "    |" << endl;
        }
        else
        {
            cout << "|                                                                                                  |" << endl;
        }
    }
}
int main()
{
    const int STUDENT_ARRAY_LENGTH = 5;
    array<string, STUDENT_ARRAY_LENGTH> studentData =
        {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Daniel,Soledad,dan@egu.edu,12,30,35,40,SOFTWARE"};

    unsigned int arr_length = 0;
    int variablePosition = 0;
    const string delimiter = ",";

    size_t pos = 0;
    string variable;

    printHeaders();

    for (int i = 0; i < STUDENT_ARRAY_LENGTH; i++)
    {
        Students student;

        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int numbersOfDaysToCompleteeachCourse[3];
        string degree;

        while ((pos = studentData[i].find(',')) != string::npos)
        {
            variable = studentData[i].substr(0, pos);

            switch (variablePosition)
            {
            case 0:
                studentID = variable;
                break;
            case 1:
                firstName = variable;
                break;
            case 2:
                lastName = variable;
                break;
            case 3:
                email = variable;
                break;
            case 4:
                age = stoi(variable);
                break;
            case 5:
            case 6:
            case 7:
                numbersOfDaysToCompleteeachCourse[arr_length] = stoi(variable);
                arr_length++;
                break;
            default:
                break;
            }

            studentData[i].erase(0, pos + delimiter.length());

            if (variablePosition == 7)
            {
                degree = studentData[i];
                variablePosition = 0;
                arr_length = 0;
            }
            else
            {
                variablePosition++;
            }
        }

        cout << "|-----------------------------------------------|" << endl;
        cout << "|                 STUDENT " << i + 1 << "                     |" << endl;
        cout << "|-----------------------------------------------|" << endl;
        cout << " Student ID         : " << studentID << endl;
        cout << " First Name         : " << firstName << endl;
        cout << " Last Name          : " << lastName << endl;
        cout << " Email              : " << email << endl;
        cout << " Age                : " << age << endl;
        cout << " Days in Course     : " << numbersOfDaysToCompleteeachCourse[0] << "," << numbersOfDaysToCompleteeachCourse[1] << "," << numbersOfDaysToCompleteeachCourse[2] << endl;
        cout << " Degree Program     : " << degree << endl;
    }

    return 0;
}