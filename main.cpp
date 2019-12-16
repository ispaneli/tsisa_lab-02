// Copyright 2019 Ilya <ilia.bezverzhenko@mail.ru>

#include "header.h"

int main() {
    std::string str = std::string(105, '#');
    std::cout << str << std::endl;
    str = std::string(42, ' ');
    std::cout << str;
    std::cout << "ЛАБОРАТОРНАЯ РАБОТА №2." << std::endl;
    str = std::string(48, ' ');
    std::cout << str;
    std::cout << "(вариант №5)" << std::endl;
    str = std::string(105, '#');
    std::cout << str << std::endl << std::endl;

    /* Задаем переменные начало и
     * конца отрезка, допустимой
     * погрешности, вектора значений
     * вероятностей непопадания при
     * каждом испытании 'q' и
     * вероятностей нахождения
     * экстремума за N итераций 'P' */
    double a = -2, b = 4, E = 0.1;
    std::vector<double> P, q;

    /* Заполяем вектор вероятностей
     * попадания в окрестность
     * экстремума вообще */
    std::cout << "  q\\P    ";
    double tmp = 0.90;
    while(tmp < 1) {
        P.push_back(tmp);
        std::cout << tmp << "      ";
        tmp += 0.01;
    }
    std::cout << std::endl;

    /* Заполняем вектор вероятностей
     * попадания в окрестность
     * экстеремума случайной точкой */
    tmp = 0.005;
    while(tmp < 0.101) {
        q.push_back(tmp);
        tmp += 0.005;
    }

    /* Просчитываем результаты для
     * всех данныз P и q */
    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            RSM(a, b, P[j], q[i]);
        }
        std::cout << std::endl;
    }

    return 0;
}
