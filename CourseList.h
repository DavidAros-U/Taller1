#pragma once
#include "Course.h"
#include <string>
#include <vector>
using namespace std;

class CourseList {
private:
    Course* head;

public:
    CourseList();
    ~CourseList();

    void addCourse(string code, string name, int maxStudents, string career, string teacherName);
    Course* findCourseByCode(string code);
    vector<Course*> findCoursesByName(string name);
    bool removeCourseByCode(string code);

    void listAllCourses();
};
