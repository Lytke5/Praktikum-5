#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

int main()
{
    string courseName;
    int answer;
    do{
    cout << "Welcome to the course management system!" << endl << endl;
    cout << "Name of your Course: ";
    cin >> courseName;
    Course* myCourse = new Course(courseName);
    do{
        do{
            system("cls");
            cout << "Welcome to the course management system!" << endl << endl;
            cout << "(1) List all students in the course" << endl << endl;
            cout << "(2) Add Student" << endl <<endl;
            cout << "(3) Show Student" << endl << endl;
            cout << "(4) Delete Student" << endl << endl;
            cout << "(5) Delete Course" << endl << endl;
            cout << "(6) Quit" << endl << endl;

            cin >>answer;
        }while (answer < 1 || answer > 6);

        system("cls");

        switch(answer)
        {
        case 1:
        {
            myCourse->ListStudents();
            break;
        }

        case 2:
        {
            string lastName;
            string firstName;
            cout<<"Lastname of the new student: ";
            cin >> lastName;
            cout<<"Firstname of the new student: ";
            cin >> firstName;
            Student* newStudent = new Student(lastName,firstName);
            myCourse->AddStudent(newStudent);
            cout << "Created new Student with the number " << newStudent->GetNumber() << "!" << endl;
            cout << "Press any key to continue" <<endl;
            char tmp;
            cin >> tmp;

            break;
        }

        case 3:
        {
            int number;
            cout<<"Number of the student: ";
            cin>>number;
            Student* currStudent;
            currStudent = myCourse->GetStudent(number);
            cout << endl;
            cout << "Lastname: " << currStudent->GetLastname() << endl;
            cout << "Firstname: " << currStudent->GetFirstname() << endl;
            cout << "Press any key to continue"<<endl;
            char tmp;
            cin >> tmp;
            break;
        }
        case 4:
        {
            int number;
            cout<<"Number of the student: ";
            cin>>number;
            myCourse->DeleteStudent(number);
            break;
        }
        case 5:
            delete myCourse;
        }


    } while (answer < 5);
    } while(answer == 5);
    return 0;
}
