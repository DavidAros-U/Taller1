#pragma once
#include <string>
using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    string career;
    string admissionDate;
    Student* next;

public:
    Student(int id, string firstName, string lastName, string career, string admissionDate);

    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    string getCareer() const;
    string getAdmissionDate() const;
    Student* getNext() const;

    void setNext(Student* nextStudent);
};
