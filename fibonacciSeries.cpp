#include <iostream>
using namespace std;

// Recursive approach
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Recursive Fibonacci series printer
void printFibonacciRecursive(int n, int a = 0, int b = 1)
{
    if (n <= 0)
        return;
    cout << a << " ";
    printFibonacciRecursive(n - 1, b, a + b);
}

// Iterative approach (Efficient)
void fibonacciSeries(int n)
{
    int a = 0, b = 1, c;
    cout << "Fibonacci Series (Iterative): ";
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacciRecursive(n) << endl;
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacciRecursive(n) << endl;

    fibonacciSeries(n);

    cout << "Fibonacci Series (Recursive): ";
    printFibonacciRecursive(n);
    cout << endl;

    return 0;
}
