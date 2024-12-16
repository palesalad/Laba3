#include <stdio.h>
#include <string.h>
#include "Student.h"
#include "Course.h"

// Позитивный тест для функции изменения средней оценки студента  желаемый вывод: УСПЕХ
void TestChangeGrade() {
    printf("=== Позитивные тесты ===\n");
    Student student = {"Илья", 21, 3.0}; 
    SetGrade(&student, 4.0); 
    
    if (student.grade == 4.0) {
        printf("Изменение средней оценки учащегося: УСПЕХ\n");
    } else {
        printf("Изменение средней оценки учащегося: ПРОВАЛ\n");
    }
}

// Позитивный тест для функции проверки, является ли студент отличником  желаемый вывод: УСПЕХ
void TestBestStudent() {
    Student student = {"Анна", 22, 4.6}; 
    
    if (BestStudent(&student) == 1) {
        printf("Проверка является ли ученик отличником: УСПЕХ\n");
    } else {
        printf("Проверка является ли ученик отличником: ПРОВАЛ\n");
    }
}

// Позитивный тест для функции добавления студента на курс  желаемый вывод: УСПЕХ
void TestAddStudentToCourse() {
    Course course = {"Математика", 0, 0.0}; 
    Student student = {"Светлана", 20, 4.5};
    
    int result = AddStudentOnCourse(&course, student); // Добавляем студентку на курс
    
    // Проверяем, что студентка была успешно добавлена и количество студентов увеличилось на 1
    if (result == 1 && course.StudentCount == 1) {
        printf("Проверка добавления учащегося на курс: УСПЕХ\n");
    } else {
        printf("Проверка добавления учащегося на курс: ПРОВАЛ\n");
    }
}

// Позитивный тест для функции поиска лучшего студента на курсе  желаемый вывод: УСПЕХ
void TestFindTopStudent() {
    Course course = {"Физика", 0, 0.0};
    Student student1 = {"Сергей", 20, 4.5}; 
    Student student2 = {"Елена", 22, 4.8}; 
    
    AddStudentOnCourse(&course, student1); 
    AddStudentOnCourse(&course, student2); 
    
    const Student* topStudent = FindTopStudent(&course); 
    
    if (topStudent->grade == 4.8) {
        printf("Поиск лучшего студента на курсе: УСПЕХ\n");
    } else {
        printf("Поиск лучшего студента на курсе: ПРОВАЛ\n");
    }
}

// Негативный тест добавляем студента на несуществующий курс
void TestNoCourse(){
    printf("=== Негативные тесты ===\n");
    Student student = {"Иван", 20, 4};
    if (AddStudentOnCourse( NULL, student)){
        printf("Добавляем на не существущий курс: УCПЕХ\n");
    } 
    else{
        printf("Добавляем на не существущий курс: ПРОВАЛ\n");
    }
}

// Негативный тест добавляем на курс количество уеников превышающее лимит
void TestOverStudents() {
    
    Course course = { "ФМШ", 0, 0.0 };
    for (int i = 0; i < 101; i++) {
        char name[100];
        snprintf(name, sizeof(name), "Студент %d", i + 1);
        Student student = { "", 18, 3.0 }; 
        strncpy(student.name, name, sizeof(student.name) - 1);
        student.name[sizeof(student.name) - 1] = '\0'; 

        if(AddStudentOnCourse(&course, student)== 0) {
            printf("Добавление 101/100 учеников: ПРОВАЛ\n");
        }
    }
}

// Крайний тест добавляем на курс ученика без данных + проверяем будет ли он считаться лучшим учеником желаемый вывод: УСПЕХ
void TestZeroStudent() {
    printf("=== Крайние случаи ===\n");
    
    Course course = { "Программирование", 0, 0.0 };
    Student emptyStudent = { };
    int result = AddStudentOnCourse(&course, emptyStudent);
    printf("Добавление студента с пустыми данными: %s\n", result ? "Успех" : "Не удалось");
    printf("Количество студентов в курсе: %d\n", course.StudentCount);

    const Student* topStudent = FindTopStudent(&course);
    if (topStudent) {
        printf("Лучший студент: %s с оценкой %.2f\n", topStudent->name, topStudent->grade);
    } else {
        printf("Нет студентов в курсе.\n");
    }
}

// Крайний тест добавляем ученика на курс без данных
void TestZeroCourse(){
    Course course = {};
    Student student = {"Саша", 30, 5};

    if (AddStudentOnCourse(&course, student)){
        printf("Студент добавлен на нулевой курс: УСПЕХ\n");
    }
    else{
        printf("Студент добавлен на нулевой курс: ПРОВАЛ\n");
    }

    const Student* topStudent = FindTopStudent(&course); 
    
    if (topStudent->grade == 5) {
        printf("Лучший студент на нулевом курсе: УСПЕХ\n");
    } else {
        printf("Лучший студент на нулевом курсе: ПРОВАЛ\n");
    }
}


// Запуск всех тестов
int main() {
    TestChangeGrade(); // тест изменения средней оценки
    TestBestStudent(); //  тест проверки отличника
    TestAddStudentToCourse(); //  тест добавления студента на курс
    TestFindTopStudent(); //  тест поиска лучшего студента
    TestNoCourse(); // тест добавления студента на несуществующий курс
    TestOverStudents(); // тест превышения кол-ва студентов на курсе
    TestZeroStudent(); // тест добавления и проверки ученика без данных
    return 0; // Завершаем программу
}