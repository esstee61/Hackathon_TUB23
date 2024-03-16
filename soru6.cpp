#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isUgly(int n) {
        if (n <= 0) return false;
        while (n%2 == 0) {
                n = n / 2;   
        }

        for (int i=3; n>i; i+=2)
            while (n%i == 0) {
                n = n / i;
                if (i > 5) {
                    return false;
                }   
            }
    return true;
    }

int main() {
    cout << isUgly(1026549767) << '\n';
}