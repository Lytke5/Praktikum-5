#include "course.h"
#include <iostream>

Course::Course(string n)
{
    head = new Student();
    tail = new Student();
    name = n;
    count = 0;
}

int Course::GetCount()
{
    return count;
}

void Course::ListStudents()
{
    Student* currStudent = nullptr;
    cout.width(20);
    cout.setf(ios::left);
    cout << "Lastname";
    cout.width(20);
    cout.setf(ios::left);
    cout << "Firstname";
    cout.width(20);
    cout.setf(ios::left);
    cout << "Number";
    cout << endl << endl;
    if(count > 0)
    {
        currStudent = head->next;

        cout.width(20);
        cout.setf(ios::left);
        cout << currStudent->GetLastname();
        cout.width(20);
        cout.setf(ios::left);
        cout << currStudent->GetFirstname();
        cout.width(20);
        cout.setf(ios::left);
        cout << currStudent->GetNumber();
        cout << endl;

        for(int i = 0; i < count-1; i++)
        {
            currStudent = currStudent->next;
            cout.width(20);
            cout.setf(ios::left);
            cout << currStudent->GetLastname();
            cout.width(20);
            cout.setf(ios::left);
            cout << currStudent->GetFirstname();
            cout.width(20);
            cout.setf(ios::left);
            cout << currStudent->GetNumber();
            cout << endl;
        }
    }
    else
    {
        cout << "Wow such empty :(" << endl << endl;
    }
    cout << "Press any key to continue" << endl;
    char tmp;
    cin >> tmp;
}

Student* Course::GetStudent(int number)
{
    Student* currStudent = nullptr;
    if(count > 0)
    {
        currStudent = head->next;

        for(int i = 0; i < count; i++)
        {
            if(currStudent->GetNumber() == number)
            {
                return currStudent;
            }
            currStudent = currStudent->next;
        }
    }
    return nullptr;
}

void Course::AddStudent(Student* s)
{
    if(count == 0)
    {
        head->next = s;
        tail->next = s;
    }
    else
    {
        tail->next->next = s;
        tail->next = s;
    }
    count++;
}

void Course::DeleteStudent(int number)
{
    Student* temp = head->next;
    Student* prev = nullptr;

    if (temp != nullptr && temp->GetNumber() == number)
    {
        head->next = temp->next;
        delete temp;
        if(count == 1)
            tail->next = nullptr;
        count--;
        return;
    }
    else
    {
        while (temp != nullptr && temp->GetNumber() != number)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;

        if(prev->next == nullptr)
            tail->next = prev;

        delete temp;
        count--;
    }
}

