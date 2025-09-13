#pragma once
#include "Student.h"
#include <string>
#include <vector>
using namespace std;

class StudentList {
private:
    Student* head;

public:
    StudentList();

    Student* findStudentById(int id);
    vector<Student*> findStudentsByName(string name);
    bool removeStudentById(int id);
    
    void addStudent(int id, string firstName, string lastName, string career, string admissionDate);
    void listAllStudents();
        ~StudentList();
};
