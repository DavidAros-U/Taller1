#include "Student.h"

Student::Student(int id, string firstName, string lastName, string career, string admissionDate) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->career = career;
    this->admissionDate = admissionDate;
    this->next = nullptr;
}

int Student::getId() const { return id; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getCareer() const { return career; }
string Student::getAdmissionDate() const { return admissionDate; }
Student* Student::getNext() const { return next; }

void Student::setNext(Student* nextStudent) {
    this->next = nextStudent;
}
