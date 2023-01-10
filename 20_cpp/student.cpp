#include "student.h"
#include <time.h>
#include <vector>

Student::Student()
{
    next = nullptr;
}
Student::Student(string ln, string fn)
{
    lastname = ln;
    firstname = fn;
    number = GenerateNumber();
    next = nullptr;   
}
string Student::GetLastname()
{
    return lastname;
}

string Student::GetFirstname()
{
    return firstname;
}

int Student::GetNumber()
{
    return number;
}

int Student::GenerateNumber()
{
    bool numberFound;
    int newNumber;
    do{
        numberFound = false;

        srand(time(0));
        newNumber = rand() % 1000000;

        for(int i = 0; i < previousNumbers.size(); i++)
        {
            if(previousNumbers[i] == newNumber)
            {
                numberFound = true;
            }
        }
    }
    while(numberFound);

    previousNumbers.push_back(newNumber);

    return newNumber;
}
