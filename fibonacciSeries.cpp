#include <iostream>
using namespace std;

// Recursive approach
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative approach (Efficient)
int fibonacciIterative(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacciRecursive(n) << endl;
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacciIterative(n) << endl;

    return 0;
}
