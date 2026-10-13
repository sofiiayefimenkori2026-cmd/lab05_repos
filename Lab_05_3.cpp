// Єфіменко Софія
// Група РІ-13
// Lab_05_3.cpp
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 8
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double s(const double x);

int main()
{
    double rp, rk, z;
    int n;

    cout << "rp = "; cin >> rp;
    cout << "rk = "; cin >> rk;
    cout << "n  = "; cin >> n;

    double dr = (rk - rp) / n;
    double r = rp;

    cout << fixed;
    cout << "--------------------------------" << endl;
    cout << "|" << setw(7)  << "r" << "     |"
         << setw(12) << "z" << "       |" << endl;
    cout << "--------------------------------" << endl;

    while (r <= rk + dr / 2)
    {
        z = s(sqrt(r) + 1) - pow(s(sqrt(r) - 1), 2) + 1;
        cout << "|" << setw(9) << setprecision(2) << r << "   |"
             << setw(16) << setprecision(5) << z << "   |" << endl;
        r += dr;
    }
    cout << "--------------------------------" << endl;
    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1)
    {
        return (1.0 + x * x + sqrt(abs(sin(x)))) / (pow(sin(2.0 * x * x), 2) + 1.0);
    }
    else
    {
        // Перша сума: від i = 0 до 5 для x^i / i!
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

        // Друга сума: від k = 1 до 6 для x^k / k!
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
