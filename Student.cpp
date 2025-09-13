#include "Student.h"

Student::Student(int id, string firstName, string lastName, string career, string admissionDate) {
    this->id = new int(id);
    this->firstName = new string(firstName);
    this->lastName = new string(lastName);
    this->career = new string(career);
    this->admissionDate = new string(admissionDate);
    this->next = nullptr;
}

Student::~Student() {
    delete id;
    delete firstName;
    delete lastName;
    delete career;
    delete admissionDate;
}

int Student::getId() const {
    return *id;
}

string Student::getFirstName() const {
    return *firstName;
}

string Student::getLastName() const {
    return *lastName;
}

string Student::getCareer() const {
    return *career;
}

string Student::getAdmissionDate() const {
    return *admissionDate;
}

Student* Student::getNext() const {
    return next;
}

void Student::setNext(Student* nextStudent) {
    this->next = nextStudent;
}
