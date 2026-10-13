// Єфіменко Софія
// Група РІ-13
// UnitTest_05_1.cpp
// Модульний тест для функції g(a, b) (Лабораторна робота № 5.1, Варіант 8)
#include <iostream>
#include <cassert>
#include <cmath>

// Прототип тестованої функції
double g(const double a, const double b);

double g(const double a, const double b)
{
    return sin(a * b) / (a * a + b * b);
}

void test_g()
{
    const double eps = 1e-5;

    // Тест 1: a = 1, b = 2 => sin(2) / (1 + 4) = sin(2) / 5 ~= 0.181859
    double expected1 = sin(2.0) / 5.0;
    assert(std::abs(g(1.0, 2.0) - expected1) < eps);
    std::cout << "Test 1 passed: g(1.0, 2.0) == " << g(1.0, 2.0) << " (~= " << expected1 << ")" << std::endl;

    // Тест 2: a = 0, b = 1 => sin(0) / (0 + 1) = 0.0
    assert(std::abs(g(0.0, 1.0) - 0.0) < eps);
    std::cout << "Test 2 passed: g(0.0, 1.0) == 0.0" << std::endl;

    // Тест 3: a = 1, b = 1 => sin(1) / (1 + 1) = sin(1) / 2 ~= 0.420735
    double expected3 = sin(1.0) / 2.0;
    assert(std::abs(g(1.0, 1.0) - expected3) < eps);
    std::cout << "Test 3 passed: g(1.0, 1.0) == " << g(1.0, 1.0) << " (~= " << expected3 << ")" << std::endl;

    // Тест 4: a = 2, b = 0 => sin(0) / (4 + 0) = 0.0
    assert(std::abs(g(2.0, 0.0) - 0.0) < eps);
    std::cout << "Test 4 passed: g(2.0, 0.0) == 0.0" << std::endl;

    // Тест 5: a = -1, b = 2 => sin(-2) / (1 + 4) = -sin(2) / 5 ~= -0.181859
    double expected5 = sin(-2.0) / 5.0;
    assert(std::abs(g(-1.0, 2.0) - expected5) < eps);
    std::cout << "Test 5 passed: g(-1.0, 2.0) == " << g(-1.0, 2.0) << " (~= " << expected5 << ")" << std::endl;

    std::cout << "\nAll Unit Tests for Lab_05_1 passed successfully!" << std::endl;
}

int main()
{
    std::cout << "Running Unit Tests for Lab_05_1 (function g)..." << std::endl;
    test_g();
    return 0;
}
