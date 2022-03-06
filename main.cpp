#include <iostream>
#include <string>
#include <array>
#include "Rooster.h"
#include "Degree.h"
#include <map>

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
        "A5,Daniel,Soledad,dan@egu.edu,12,30,35,40,SOFTWARE" };

    int variablePosition = 0;
    const string delimiter = ",";

    size_t pos = 0;
    string variable;

    Rooster classRooster;

    printHeaders();

    for (int i = 0; i < STUDENT_ARRAY_LENGTH; i++)
    {
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age = 0;
        int dayOne = 0, dayTwo = 0, dayThree =0;
        DegreeProgram degree = SOFTWARE;

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
                dayOne = stoi(variable);
            case 6:
                dayTwo = stoi(variable);
            case 7:
                dayThree = stoi(variable);
                break;
            default:
                break;
            }

            studentData[i].erase(0, pos + delimiter.length());

            if (variablePosition == 7)
            {   
                map<string, DegreeProgram> DegreeProgramMap = {
                     {"SECURITY", DegreeProgram::SECURITY},
                     {"NETWORK",  DegreeProgram::NETWORK},
                     {"SOFTWARE", DegreeProgram::SOFTWARE}
                };
                degree = DegreeProgramMap[studentData[i]];
                variablePosition = 0;
            }
            else
            {
                variablePosition++;
            }
        };
        classRooster.add(
            studentID, 
            firstName, 
            lastName, 
            email, 
            age, 
            dayOne, 
            dayTwo, 
            dayThree, 
            degree);
        
    }
    //print all
    classRooster.printAll();
    //invalid emails
    classRooster.printInvalidEmails();

    //loop thru and pass the id and print averege, I printing them from back to front
    for (int i = classRooster.students.size() - 1; i >= 0 ; i--)
    {
        classRooster.printAverageDaysInCourse(classRooster.students[i]->getStudentID());
    };

    classRooster.printByDegreeProgram(SOFTWARE);

    //remove
    classRooster.remove("A3");

    //print all
    classRooster.printAll();

    classRooster.remove("A3");

    return 0;
}