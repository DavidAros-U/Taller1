#include "CourseList.h"
#include <iostream>
using namespace std;

CourseList::CourseList() {
    head = nullptr;
}

CourseList::~CourseList() {
    Course* current = head;
    while (current) {
        Course* next = current->getNext();
        delete current;
        current = next;
    }
}

void CourseList::addCourse(string code, string name, int maxStudents, string career, string teacherName) {
    Course* newCourse = new Course(code, name, maxStudents, career, teacherName);

    if (!head) {
        head = newCourse;
    } else {
        Course* temp = head;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newCourse);
    }
}

Course* CourseList::findCourseByCode(string code) {
    Course* temp = head;
    while (temp) {
        if (temp->getCode() == code) return temp;
        temp = temp->getNext();
    }
    return nullptr;
}

vector<Course*> CourseList::findCoursesByName(string name) {
    vector<Course*> result;
    Course* temp = head;
    while (temp) {
        if (temp->getName() == name) {
            result.push_back(temp);
        }
        temp = temp->getNext();
    }
    return result;
}

bool CourseList::removeCourseByCode(string code) {
    if (!head) return false;

    if (head->getCode() == code) {
        Course* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    Course* current = head;
    while (current->getNext()) {
        if (current->getNext()->getCode() == code) {
            Course* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            return true;
        }
        current = current->getNext();
    }

    return false;
}

void CourseList::listAllCourses() {
    Course* temp = head;
    while (temp) {
        cout << "Code: " << temp->getCode()
             << ", Name: " << temp->getName()
             << ", Max Students: " << temp->getMaxStudents()
             << ", Career: " << temp->getCareer()
             << ", Teacher: " << temp->getTeacherName() << endl;
        temp = temp->getNext();
    }
}
