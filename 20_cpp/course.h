#ifndef COURSE_H
#define COURSE_H
#include "student.h"


class Course
{
public:
    Course(string n);
    int GetCount();
    void ListStudents();
    Student* GetStudent(int number);
    void AddStudent(Student* s);
    void DeleteStudent(int number);
private:
    Student* head;
    Student* tail;
    string name;
    int count;
};

#endif // COURSE_H
