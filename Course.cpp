#include "Course.h"

Course::Course(string code, string name, int maxStudents, string career, string teacherName) {
    this->code = new string(code);
    this->name = new string(name);
    this->maxStudents = new int(maxStudents);
    this->career = new string(career);
    this->teacherName = new string(teacherName);
    this->next = nullptr;
}

Course::~Course() {
    delete code;
    delete name;
    delete maxStudents;
    delete career;
    delete teacherName;
}

string Course::getCode() const {
    return *code;
}

string Course::getName() const {
    return *name;
}

int Course::getMaxStudents() const {
    return *maxStudents;
}

string Course::getCareer() const {
    return *career;
}

string Course::getTeacherName() const {
    return *teacherName;
}

Course* Course::getNext() const {
    return next;
}

void Course::setNext(Course* nextCourse) {
    this->next = nextCourse;
}
