// Єфіменко Софія
// Група РІ-13
// Lab_05_4.cpp
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 8
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double P0(const int K, const int N);
double P1(const int K, const int N, const int i);
double P2(const int K, const int N, const int i);
double P3(const int K, const int N, const int i, double t);
double P4(const int K, const int N, const int i, double t);

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|  Method                 |  Result             |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|  iter (P0)              | " << setw(19) << right << setprecision(5) << P0(K, N) << " |" << endl;
    cout << "|  rec up ++ (P1)         | " << setw(19) << right << setprecision(5) << P1(K, N, K) << " |" << endl;
    cout << "|  rec up -- (P2)         | " << setw(19) << right << setprecision(5) << P2(K, N, N) << " |" << endl;
    cout << "|  rec down ++ (P3)       | " << setw(19) << right << setprecision(5) << P3(K, N, K, 1.0) << " |" << endl;
    cout << "|  rec down -- (P4)       | " << setw(19) << right << setprecision(5) << P4(K, N, N, 1.0) << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    return 0;
}

double P0(const int K, const int N)
{
    double p = 1.0;
    for (int i = K; i <= N; i++)
        p *= (1.0 * K / i + 1.0 * i / N);
    return p;
}

double P1(const int K, const int N, const int i)
{
    if (i > N)
        return 1.0;
    else
        return (1.0 * K / i + 1.0 * i / N) * P1(K, N, i + 1);
}

double P2(const int K, const int N, const int i)
{
    if (i < K)
        return 1.0;
    else
        return (1.0 * K / i + 1.0 * i / N) * P2(K, N, i - 1);
}

double P3(const int K, const int N, const int i, double t)
{
    t = t * (1.0 * K / i + 1.0 * i / N);
    if (i >= N)
        return t;
    else
        return P3(K, N, i + 1, t);
}

double P4(const int K, const int N, const int i, double t)
{
    t = t * (1.0 * K / i + 1.0 * i / N);
    if (i <= K)
        return t;
    else
        return P4(K, N, i - 1, t);
}
