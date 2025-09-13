#pragma once
#include <string>
using namespace std;

class Course {
private:
    string* code;
    string* name;
    int* maxStudents;
    string* career;
    string* teacherName;
    Course* next;

public:
    Course(string code, string name, int maxStudents, string career, string teacherName);
    ~Course();

    string getCode() const;
    string getName() const;
    int getMaxStudents() const;
    string getCareer() const;
    string getTeacherName() const;
    Course* getNext() const;

    void setNext(Course* nextCourse);
};
