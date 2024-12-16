#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[100];
    int age;
    double grade;
    int id;
} Student;

int StudentsDataCheck(Student *student);
void SetGrade(Student *student, float NewGrade); 
int BestStudent(Student *student); 
int GetStudentData(Student* student);

#endif
