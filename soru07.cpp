#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<bool> soldiers(int n);

int main() 
{  
    int SIZE = 1389;
    vector<bool> sold = soldiers(SIZE); 
    // zeros are left, ones are right
    
    // for (int i=1; i<=SIZE; i++) {
    //     cout << setw(2) << sold[i] << ' ';
    // }
    // cout << '\n';
    // for (int i=1; i<=SIZE; i++) {
    //     cout << setw(2) << i << ' ';
    // }
    // cout << '\n';

    bool replace;
    int counter = 0;
    bool temp;
    do {
        replace = false;
        for (int i=1; i<SIZE; i++) {
            if (sold[i] && not sold[i+1]) {
                temp = sold[i];
                sold[i] = sold[i+1];
                sold[i+1] = temp;
                replace = true;
                i++;
            }
        }

        // cout << "\n___" << counter << "___\n";
        // for (int i=1; i<=SIZE; i++) {
        //     cout << sold[i] << ' ';
        // }
        // cout << "\n";

        counter++;
    } while (replace);

    cout << counter-1 << " duduk sonra goz temasi kuran asker kalmaz.\n";

    return 0;
}

vector<bool> soldiers(int n) 
{
    vector<bool> soldierlist;
    int primecount = n-1;
    for (int i=0; i<=n; ++i) {
        if (i == 1) soldierlist.push_back(0);
        else soldierlist.push_back(1);
    }

    int x = 2;
    while (pow(x, 2) <= n) {
        if (soldierlist[x]) {
            for (int i=pow(x, 2); i<=n; i+=x) {
                soldierlist[i] = 0;
            }
        }
        ++x;
    }

    return soldierlist;
}