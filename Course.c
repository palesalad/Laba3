#include "Course.h"
#include <stdio.h>

int CourseCheckData(Course* course)
{
    if (course == NULL) 
    {
        printf("ОШИБКА: Курса не существует\n");
        return 0;
    }
    return 1;
}
int AddStudentOnCourse (Course *course, Student student) {
    if (CourseCheckData(course)) {
        if (course->StudentCount < 100) { 
            course->student[course->StudentCount] = student; 
            course->StudentCount++;
            if (student.grade > course->MaxMiddleGrade) {
                course->MaxMiddleGrade = student.grade;
                }

                return 1; 
            } 
            else {
            printf("ОШИБКА: Превышено максимальное количество студентов\n");
            return 0; 
        }
        return 1;
    }   
    return 0; 
}

const Student* FindTopStudent(const Course *course){
    if (course-> StudentCount == 0) return NULL;
    const Student *TopStudent = &course->student[0];

    for (int i=1; i< course -> StudentCount; i++){
        if (course->student[i].grade > TopStudent ->grade){
            TopStudent = &course->student[i];
        }
    }
    return TopStudent;
}