#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> dizi = {3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4, 11, 13, 12, 10, 5, 2, 5, 8, 11};
    int dizilen = dizi.size();
    int counter = 2;
    bool artan = (dizi[0] < dizi[1]) ? true : false;
    
    int maxlen = 2;
    int lastind = 1;

    for (int i=1; i<dizilen-1; ++i) {
        if (dizi[i] <= dizi[i+1] && artan) {
            ++counter;
        }
        else if (dizi[i] < dizi[i+1] && !artan) {
            artan = true;

            if (maxlen < counter) {
                maxlen = counter;
                lastind = i;
            }

            counter = 2;
        }
        else if (dizi[i+1] < dizi[i] && artan) {
            artan = false;
            ++counter;
        }
        else if (dizi[i+1] <= dizi[i] && !artan) {
            ++counter;
        }
    }
    if (maxlen < counter) {
        maxlen = counter;
        lastind = dizilen-1;
    }

    cout << "index: " << lastind-maxlen+1 << " - " << lastind << "\n";

    cout << "uzunluk: " << maxlen << "\n";
    return 0;
}