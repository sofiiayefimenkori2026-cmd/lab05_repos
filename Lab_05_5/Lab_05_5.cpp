// Єфіменко Софія
// Група РІ-13
// Lab_05_5.cpp
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 8
#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int n, int m, int level, int& depth);
int gcd_iter(int n, int m);

int main()
{
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;

    if (n <= 0 || m <= 0)
    {
        cout << "Error: n and m must be natural numbers (n > 0, m > 0)!" << endl;
        return 1;
    }

    int depth = 0;
    cout << "--------------------------------------------------------" << endl;
    cout << "|  Level (level)   |   Parameter n   |   Parameter m   |" << endl;
    cout << "--------------------------------------------------------" << endl;

    int result = gcd(n, m, 1, depth);

    cout << "--------------------------------------------------------" << endl;
    cout << "|  Recursion depth (depth)           | " << setw(15) << right << depth << " |" << endl;
    cout << "|  GCD (recursive)                   | " << setw(15) << right << result << " |" << endl;
    cout << "|  GCD (iterative)                   | " << setw(15) << right << gcd_iter(n, m) << " |" << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}

int gcd(int n, int m, int level, int& depth)
{
    if (level > depth)
        depth = level;

    cout << "| " << setw(16) << right << level << " "
         << "| " << setw(15) << right << n << " "
         << "| " << setw(15) << right << m << " |" << endl;

    if (n % m == 0)
        return m;
    else
        return gcd(m, n % m, level + 1, depth);
}

int gcd_iter(int n, int m)
{
    while (m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}
