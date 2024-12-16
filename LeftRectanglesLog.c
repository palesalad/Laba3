#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double Function(double x) {
    return log(x);
}

double LeftRectangelInegral(double a, double b, double E) {
    int n = 1; 
    double h, IntegNew, IntegOld;

    do {
        h = (b - a) / n;
        IntegNew = 0.0;

        for (int i = 0; i < n; i++) {
            IntegNew += Function(a + i * h) * h;
        }

        IntegOld = IntegNew;
        n *= 2; 

    } while (fabs(IntegNew-IntegOld) >= E);

    return IntegNew;
}

int GetDoubleInput(double *value) {
    char input[100];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *endptr;
        *value = strtod(input, &endptr);
        if (endptr == input || *endptr != '\n') {
            return 0; 
        }
        return 1; 
    }
    return 0;
}

int main() {
    double a, b, E;

    printf("Введите нижний предел интегрирования (a): ");
    while (!GetDoubleInput(&a)) {
        printf("Ошибка: введено некорректное значение. Пожалуйста, попробуйте снова.\n");
    }

    printf("Введите верхний предел интегрирования (b): ");
    while (!GetDoubleInput(&b) || b <= a) {
        printf("Ошибка: введено некорректное значение. Пожалуйста, попробуйте снова.\n");
    }

    printf("Введите погрешность (E): ");
    while (!GetDoubleInput(&E) || E <= 0) {
        printf("Ошибка: введено некорректное значение. Пожалуйста, попробуйте снова.\n");
    }

    double result = LeftRectangelInegral(a, b, E);
    printf("Результат интегрирования: %.10f\n", result);

    return 0;
}