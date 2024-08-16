#include <iostream>


using namespace std;

int main() 
{   
    int size;

    do {
        cout << "Polinom derecesini giriniz: ";
        cin >> size;
    } while (size<1);

    int katsayilar[size];

    cout << "Polinom katsayilarini sirasiyla giriniz:\n";

    for (int i=0; i<size+1; ++i) {
        cout << "a" << i << ": ";
        cin >> katsayilar[i];
    }


    cout << "polinom: ";

    for (int i=size; i>=0; --i) {
        cout << katsayilar[i];
        if (i==1) cout << "x + ";
        else if (i==0) cout << "\n";
        else cout << "x^" << i << " + ";
    }
    
    cout << "turevi: ";
    for (int i=size; i>=1; --i) {
        cout << katsayilar[i] * i;
        if (i==2) cout << "x + ";
        else if (i==1) cout << "\n";
        else cout << "x^" << i-1 << " + ";
    }

    return 0;
}