#include "Student.h"
#include <stdio.h>

int StudentsDataCheck(Student* student){
    if (student == NULL){
        printf("ОШИБКА: Учащийся не зарегестрирован\n");
        return 0; 
    }

    return 1; 
}

void SetGrade(Student *student, float NewGrade){
    if (StudentsDataCheck(student)){
    student->grade = NewGrade;
    }
    else{
        printf("Не возможно заменить балл - учащийся не зарегестрирован");
    }
}

int BestStudent(Student *student){
    if (StudentsDataCheck(student)){
    return student->grade >= 4.5;
    }
    else{
    return 0;
    }

}
