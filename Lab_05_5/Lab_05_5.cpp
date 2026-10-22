// Єфіменко Софія
// Група РІ-13
// Lab_05_5.cpp
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 8
#include <iostream>
#include <iomanip>

using namespace std;

// Прототипи функцій
int gcd(int n, int m, int level, int& depth); // рекурсивна
int gcd_iter(int n, int m);                   // ітераційна для контролю

int main()
{
    int n, m;
    // Введення вхідних чисел
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;

    // Перевірка на натуральність (n > 0, m > 0)
    if (n <= 0 || m <= 0)
    {
        cout << "Error: n and m must be natural numbers (n > 0, m > 0)!" << endl;
        return 1;
    }

    int depth = 0; // фіксація максимальної глибини
    cout << "--------------------------------------------------------" << endl;
    cout << "|  Level (level)   |   Parameter n   |   Parameter m   |" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Запуск рекурсії з рівня 1
    int result = gcd(n, m, 1, depth);

    // Виведення підсумкових результатів
    cout << "--------------------------------------------------------" << endl;
    cout << "|  Recursion depth (depth)           | " << setw(15) << right << depth << " |" << endl;
    cout << "|  GCD (recursive)                   | " << setw(15) << right << result << " |" << endl;
    cout << "|  GCD (iterative)                   | " << setw(15) << right << gcd_iter(n, m) << " |" << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}

// Рекурсивна функція обчислення НСД за алгоритмом Евкліда
int gcd(int n, int m, int level, int& depth)
{
    // Фіксація максимальної глибини рекурсії
    if (level > depth)
        depth = level;

    // Друк поточного рядка трасування (рівень, n, m)
    cout << "| " << setw(16) << right << level << " "
         << "| " << setw(15) << right << n << " "
         << "| " << setw(15) << right << m << " |" << endl;

    // Базовий випадок: якщо n ділиться на m націло — дільник знайдено
    if (n % m == 0)
        return m;
    else
        // Рекурсивний крок: ділимо m на остачу (n % m), рівень + 1
        return gcd(m, n % m, level + 1, depth);
}

// Ітераційна функція через цикл while для перевірки результату
int gcd_iter(int n, int m)
{
    while (m != 0)
    {
        int r = n % m; // залишок від ділення
        n = m;         // зсув чисел
        m = r;
    }
    return n; // повернення знайденого НСД
}
