// Єфіменко Софія
// Група РІ-13
// UnitTest_05_3.cpp
// Модульний тест для функції s(x) (Лабораторна робота № 5.3, Варіант 8)
#include <iostream>
#include <cassert>
#include <cmath>

double s(const double x);

double s(const double x)
{
    if (std::abs(x) >= 1)
    {
        return (1.0 + x * x + std::sqrt(std::abs(std::sin(x)))) / (std::pow(std::sin(2.0 * x * x), 2) + 1.0);
    }
    else
    {
        double S1 = 0;
        int i = 0;
        double a = 1.0;
        S1 = a;
        do {
            i++;
            double R = x / i;
            a *= R;
            S1 += a;
        } while (i < 5);

        double S2 = 0;
        int k = 1;
        double b = x;
        S2 = b;
        do {
            k++;
            double R = x / k;
            b *= R;
            S2 += b;
        } while (k < 6);

        return S1 + S2;
    }
}

void test_s()
{
    const double eps = 1e-5;

    // Тест 1: |x| < 1, x = 0.0 => S1 = 1, S2 = 0 => s = 1.0
    double res0 = s(0.0);
    assert(std::abs(res0 - 1.0) < eps);
    std::cout << "Test 1 passed: s(0.0) == " << res0 << " (~= 1.0)" << std::endl;

    // Тест 2: |x| < 1, x = 0.5
    double expected05 = 2.297464;
    double res05 = s(0.5);
    assert(std::abs(res05 - expected05) < 1e-4);
    std::cout << "Test 2 passed: s(0.5) == " << res05 << " (~= " << expected05 << ")" << std::endl;

    // Тест 3: |x| < 1, x = -0.5
    double expected_neg05 = 0.213083;
    double res_neg05 = s(-0.5);
    assert(std::abs(res_neg05 - expected_neg05) < 1e-4);
    std::cout << "Test 3 passed: s(-0.5) == " << res_neg05 << " (~= " << expected_neg05 << ")" << std::endl;

    // Тест 4: |x| >= 1, x = 1.0
    double expected1 = (1.0 + 1.0 + std::sqrt(std::abs(std::sin(1.0)))) / (std::pow(std::sin(2.0), 2) + 1.0);
    double res1 = s(1.0);
    assert(std::abs(res1 - expected1) < eps);
    std::cout << "Test 4 passed: s(1.0) == " << res1 << " (~= " << expected1 << ")" << std::endl;

    // Тест 5: |x| >= 1, x = -1.0 (парність/симетрія функції)
    double res_neg1 = s(-1.0);
    assert(std::abs(res_neg1 - expected1) < eps);
    std::cout << "Test 5 passed: s(-1.0) == " << res_neg1 << " (~= " << expected1 << ")" << std::endl;

    // Тест 6: |x| >= 1, x = 2.0
    double expected2 = (1.0 + 4.0 + std::sqrt(std::abs(std::sin(2.0)))) / (std::pow(std::sin(8.0), 2) + 1.0);
    double res2 = s(2.0);
    assert(std::abs(res2 - expected2) < eps);
    std::cout << "Test 6 passed: s(2.0) == " << res2 << " (~= " << expected2 << ")" << std::endl;

    std::cout << "\nAll Unit Tests for Lab_05_3 passed successfully!" << std::endl;
}

int main()
{
    std::cout << "Running Unit Tests for Lab_05_3 (function s)..." << std::endl;
    test_s();
    return 0;
}
