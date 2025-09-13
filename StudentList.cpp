#include "StudentList.h"
#include <iostream>
using namespace std;

StudentList::StudentList() {
    head = nullptr;
}

StudentList::~StudentList() {
    Student* current = head;
    while (current) {
        Student* next = current->getNext();
        delete current;
        current = next;
    }
}

void StudentList::addStudent(int id, string firstName, string lastName, string career, string admissionDate) {
    Student* newStudent = new Student(id, firstName, lastName, career, admissionDate);

    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->getNext()) temp = temp->getNext();
        temp->setNext(newStudent);
    }
}

Student* StudentList::findStudentById(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->getId() == id) return temp;
        temp = temp->getNext();
    }
    return nullptr;
}

vector<Student*> StudentList::findStudentsByName(string name) {
    vector<Student*> result;
    Student* temp = head;
    while (temp) {
        if (temp->getFirstName() == name) result.push_back(temp);
        temp = temp->getNext();
    }
    return result;
}

bool StudentList::removeStudentById(int id) {
    if (!head) return false;

    if (head->getId() == id) {
        Student* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    Student* current = head;
    while (current->getNext()) {
        if (current->getNext()->getId() == id) {
            Student* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            return true;
        }
        current = current->getNext();
    }

    return false;
}

void StudentList::listAllStudents() {
    Student* temp = head;
    while (temp) {
        cout << "ID: " << temp->getId()
             << ", Name: " << temp->getFirstName() << " " << temp->getLastName()
             << ", Career: " << temp->getCareer()
             << ", Admission: " << temp->getAdmissionDate() << endl;
        temp = temp->getNext();
    }
}
