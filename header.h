// Copyright 2019 Ilya <ilia.bezverzhenko@mail.ru>

#ifndef __LAB2_HEADER_H
#define __LAB2_HEADER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

// Выдает значение функции в заданной точке.
double Function(const double& x) {
    return (double) - cos(0.5 * x) - 1;
}

// Выдает случаный double на заданном отрезке.
double RAND(const double& min, const double& max) {
    double result = (double)rand() / RAND_MAX;
    return min + result * (max - min);
}

// Random Search Method
/* По заданным вероятностям высчитывает
 * необходимое количество интераций
 * по случайному выбору точки, которое
 * обеспечит данные вероятности */
void RSM(double& begin, double& end, double& P, double& q) {
    // Число итераций.
    size_t N = log(1 - P) / log(1 - q);

    double X_min = begin, Y_min = Function(begin), Xi = 0;

    // Выполняем 'N' итераций.
    for (size_t i = 0; i < N; ++i) {
        Xi = RAND(begin, end);

        // Проверям выполнение условия.
        if (Function(Xi) < Y_min) {
            Y_min = Function(Xi);
            X_min = Xi;
        }
    }

    // Выводим значения.
    std::cout << std::fixed << std::setprecision(5) << std::right;
    std::cout << std::setw(10) << Y_min;
}

#endif //__LAB2_HEADER_H
