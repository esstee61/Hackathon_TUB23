#include <iostream>

using namespace std;

int fibonacci(int n);
bool ulonachi(int x);

int main() 
{
    for (int i=1; i<100; ++i) {
        if (ulonachi(i)) cout << i << '\n';
    }
    return 0;
}

int fibonacci(int n)   // n=0 ve n=1 iken 1 dondurur
{
    int a0 = 0;
    int a1 = 1;
    int a2 = 1;
    for (int i=0; i<n; ++i) {
        a2 = a1 + a0;
        a0 = a1;
        a1 = a2;
    }
    return a2;
}

bool ulonachi(int x)
{
    for (int i=2; fibonacci(i)<x; ++i) {
        if (x % fibonacci(i) == 0) return false;
    }

    return true;
}
