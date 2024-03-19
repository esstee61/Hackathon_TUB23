#include <iostream>
#include <vector>

using namespace std;

int randnum(int  i, int j);

int main() 
{
    vector<vector<int>> matrix; 
    const int SIZE = 9;

    srand(time(nullptr));  // rastgele matriks olusturma
    for (int j=0; j<SIZE; ++j) {
        vector<int> row;
        for (int i=0; i<SIZE; ++i) {
            row.push_back(randnum(0, 10));
        }
        matrix.push_back(row);
    }

    for (auto &r : matrix) {  // print matriks
        for (int i=0; i<SIZE; ++i) {
            if (r[i]>=0) cout << " ";
            cout << r[i] << " ";
        }
        cout << "\n";
    }

    // r: c values SIZE = 9
    // 1: 0 
    // 2: 0,1 
    // 3: 0,1,2  
    // 4: 0,1,2,3
    // 5: 0,1,2
    // 6: 0,1
    // 7: 0

    int sumleft = 0;
    for (int r=1; r<SIZE-1; ++r) {
        for (int c=0; c<r && c<SIZE-1-r; ++c) {
            sumleft += matrix[r][c];
        }
    }
    // cout << sumleft << " + "; 

    int sumright = 0;
    for (int r=SIZE-2; r>0; --r) {  // r = 1
        for (int c=SIZE-1; c>r && c>SIZE-1-r; --c) {
            sumright += matrix[r][c];
        }
    }
    // cout << sumright << " = ";
    cout << sumleft + sumright << '\n';

    return 0;
}

int randnum(int i, int j)
{
    return (rand() % (j-i)) + i;
}
