// Єфіменко Софія
// Група РІ-13
// UnitTest_05_2.cpp
// Модульний тест для функцій A та S (Лабораторна робота № 5.2, Варіант 8)
#include <iostream>
#include <cassert>
#include <cmath>

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

void S(const double x, const double eps, int &n, double &s)
{
    const double PI = 4.0 * std::atan(1.0);
    n = 0;
    double a = -1.0 / x;
    s = PI / 2.0 + a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (std::abs(a) >= eps);
}

void A(const double x, const int n, double &a)
{
    double R = - (2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x);
    a *= R;
}

void test_A()
{
    const double eps = 1e-7;

    // Тест 1: x = 2, n = 1, a = -0.5 => R = -1/(3*4) = -1/12 => a = (-0.5)*(-1/12) = 1/24 ~= 0.0416667
    double a1 = -0.5;
    A(2.0, 1, a1);
    assert(std::abs(a1 - (1.0 / 24.0)) < eps);
    std::cout << "Test A.1 passed: a1 = " << a1 << " == 1/24" << std::endl;

    // Тест 2: x = 2, n = 2, a = 1/24 => R = -3/(5*4) = -3/20 => a = (1/24)*(-3/20) = -1/160 = -0.00625
    double a2 = 1.0 / 24.0;
    A(2.0, 2, a2);
    assert(std::abs(a2 - (-1.0 / 160.0)) < eps);
    std::cout << "Test A.2 passed: a2 = " << a2 << " == -1/160" << std::endl;

    // Тест 3: x = 3, n = 1, a = -1/3 => R = -1/(3*9) = -1/27 => a = 1/81
    double a3 = -1.0 / 3.0;
    A(3.0, 1, a3);
    assert(std::abs(a3 - (1.0 / 81.0)) < eps);
    std::cout << "Test A.3 passed: a3 = " << a3 << " == 1/81" << std::endl;

    // Тест 4: x = 2, n = 3, a = -1/160 => R = -5/(7*4) = -5/28 => a = 1/896
    double a4 = -1.0 / 160.0;
    A(2.0, 3, a4);
    assert(std::abs(a4 - (1.0 / 896.0)) < eps);
    std::cout << "Test A.4 passed: a4 = " << a4 << " == 1/896" << std::endl;
}

void test_S()
{
    const double eps = 1e-5;
    int n = 0;
    double s = 0.0;

    // Тест 1: x = 2.0, eps = 1e-5 => atan(2.0) ~= 1.1071487
    S(2.0, 1e-5, n, s);
    assert(std::abs(s - std::atan(2.0)) < eps);
    std::cout << "Test S.1 passed: S(2.0) == " << s << " (~= " << std::atan(2.0) << "), n = " << n << std::endl;

    // Тест 2: x = 1.5, eps = 1e-5 => atan(1.5) ~= 0.9827937
    S(1.5, 1e-5, n, s);
    assert(std::abs(s - std::atan(1.5)) < eps);
    std::cout << "Test S.2 passed: S(1.5) == " << s << " (~= " << std::atan(1.5) << "), n = " << n << std::endl;

    // Тест 3: x = 3.0, eps = 1e-5 => atan(3.0) ~= 1.2490457
    S(3.0, 1e-5, n, s);
    assert(std::abs(s - std::atan(3.0)) < eps);
    std::cout << "Test S.3 passed: S(3.0) == " << s << " (~= " << std::atan(3.0) << "), n = " << n << std::endl;

    // Тест 4: x = 5.0, eps = 1e-5 => atan(5.0) ~= 1.3734007
    S(5.0, 1e-5, n, s);
    assert(std::abs(s - std::atan(5.0)) < eps);
    std::cout << "Test S.4 passed: S(5.0) == " << s << " (~= " << std::atan(5.0) << "), n = " << n << std::endl;
}

int main()
{
    std::cout << "Running Unit Tests for Lab_05_2 (functions A and S)..." << std::endl;
    test_A();
    test_S();
    std::cout << "\nAll Unit Tests for Lab_05_2 passed successfully!" << std::endl;
    return 0;
}
