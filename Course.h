#ifndef  COURSE_H
#define  COURSE_H
#include "Student.h"

typedef struct {
    char CourseName[100];
    int StudentCount;
    double MaxMiddleGrade;
    Student student[100];
} Course;

int AddStudentOnCourse (Course *course, Student student);
int CourseCheckData(Course* CurrentCourse);
const Student* FindTopStudent(const Course *course);

#endif