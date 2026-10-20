// Єфіменко Софія
// Група РІ-13
// Lab_05_5.cpp
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 8
#include <iostream>

using namespace std;

int gcd(int n, int m, int level, int& depth);
int gcd_iter(int n, int m);

int main()
{
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;

    int depth = 0;
    cout << "Recursive calls (levels):" << endl;
    int result = gcd(n, m, 1, depth);

    cout << "GCD(" << n << ", " << m << ") = " << result << endl;
    cout << "depth = " << depth << endl;
    cout << "(iter) GCD = " << gcd_iter(n, m) << endl;

    return 0;
}

int gcd(int n, int m, int level, int& depth)
{
    if (level > depth)
        depth = level;
    cout << "level = " << level << endl;
    if (m == 0)
        return n;
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
