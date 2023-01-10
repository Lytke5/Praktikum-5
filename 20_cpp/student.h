#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>

using namespace std;


class Student
{
public:
    Student();
    Student(string ln, string fn);
    string GetLastname();
    string GetFirstname();
    int GetNumber();
    vector<int> previousNumbers; //static geht nicht?!
    Student* next;
private:
    string lastname;
    string firstname;
    int number;

    int GenerateNumber();

};

#endif // STUDENT_H
