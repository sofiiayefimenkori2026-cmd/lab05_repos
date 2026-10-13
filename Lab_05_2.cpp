// Єфіменко Софія
// Група РІ-13
// Lab_05_2.cpp
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 8
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp  = "; cin >> xp;
    cout << "xk  = "; cin >> xk;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5)  << "x"       << "     |"
         << setw(10) << "atan(x)" << "   |"
         << setw(7)  << "S"       << "      |"
         << setw(5)  << "n"       << "   |"
         << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7)  << setprecision(2) << x       << "   |"
             << setw(10) << setprecision(5) << atan(x)   << "   |"
             << setw(10) << setprecision(5) << s         << "   |"
             << setw(5)  <<                    n         << "   |"
             << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
    const double PI = 4.0 * atan(1.0);
    n = 0;
    double a = -1.0 / x;
    s = PI / 2.0 + a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double &a)
{
    double R = - (2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x);
    a *= R;
}
