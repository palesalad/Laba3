#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "Course.h"

int GetStudentData(Student* student) {
    if (student == NULL) return 0;

    printf("Введите имя студента: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; 
    printf("Введите возраст студента: ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    
    if (sscanf(input, "%d", &student->age) != 1 || student->age <= 0) {
        printf("Ошибка: некорректный ввод возраста.\n");
        return 0; // Ошибка ввода
    }

    printf("Введите средний балл студента: ");
    float grade;
    if (scanf("%f", &grade) != 1 || grade < 0 || grade > 5) {
        printf("Ошибка: некорректный ввод среднего балла.\n");
        return 0; // Ошибка ввода
    }
    
    SetGrade(student, grade);
    student -> id++;
    return 1; // Успех
}
    
int main() {
    int work = 1, input;
    while ( work ==1){
        printf("Введите значение операции: \n 1 - изменить средний балл ученика \n 2 - проверить имеет ли ученик результат отлично \n 3 - добавить ученика на курс \n 4 - выйти из программы");
        scanf(input, "%d");
        if (input ==1){
            int GetStudentData(Student* student);
        }
    }
    Course course = {"Aperture Science", 0, 0};
    
    Student student;

    if (GetStudentData(&student)) {
        AddStudentOnCourse(&course, student);
        
        const Student* TopStudent = FindTopStudent(&course);
        if (TopStudent != NULL) 
        {
            printf("Лучший студент: %s\n", TopStudent->name);
        }
    }

    return 0;
}
