#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

pair<int, bool> maxzero(vector<vector<int>> matrix);
long long cofdeterminant(vector<vector<int>> matrix);
vector<vector<int>> truncmatrix(vector<vector<int>> matrix, int row, int col);
int randnum(int i, int j);

int main()
{   
    auto start = std::chrono::high_resolution_clock::now();
    srand(time(nullptr));

    vector<vector<int>> matrix; 

    const int SIZE = 11;

    for (int j=0; j<SIZE; ++j) {
        vector<int> row;
        for (int i=0; i<SIZE; ++i) {
            row.push_back(randnum(-4, 6));
        }
        matrix.push_back(row);
    }

    for (auto &r : matrix) {
        for (int i=0; i<SIZE; ++i) {
            if (r[i]>=0) cout << " ";
            cout << r[i] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n" << maxzero(matrix).first << " - " << maxzero(matrix).second << "\n\n";

    cout << cofdeterminant(matrix) << "\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    cout << duration.count() << " seconds.";

    return 0;
}

vector<vector<int>> truncmatrix(vector<vector<int>> matrix, int row, int col)
{   
    int mlen = matrix.size();

    vector<vector<int>> newm;

    for (int i=0; i<mlen; ++i) {
        vector<int> rowmatrix;
        if (i==row) continue;
        for (int j=0; j<mlen; ++j) {
            if (j==col) continue;
            rowmatrix.push_back(matrix[i][j]);
        }
        newm.push_back(rowmatrix);
    }
    return newm;
}

long long cofdeterminant(vector<vector<int>> matrix) 
{
    int mlen = matrix.size();
    if (mlen == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    pair<int, bool> maxzeroinfo = maxzero(matrix);

    int row = (maxzeroinfo.second) ? maxzeroinfo.first: 0;
    int col = (maxzeroinfo.second) ? 0: maxzeroinfo.first;
    int lenr = (maxzeroinfo.second) ? maxzeroinfo.first+1: mlen;
    int lenc = (maxzeroinfo.second) ? mlen: maxzeroinfo.first+1;

    long long sum = 0;
    long long multiply = 1;

    for (int i=row; i<lenr; ++i) {
        for (int j=col; j<lenc; ++j) {
            if (matrix[i][j] == 0) continue; 
            multiply *= matrix[i][j];
            multiply = ((i+j) % 2 == 0) ? multiply:multiply*-1;
            multiply *= cofdeterminant(truncmatrix(matrix, i, j));
            
            sum += multiply;
            multiply = 1;
        }
    }
    return sum;
}

int randnum(int i, int j)
{
    return (rand() % (j-i)) + i;
}

pair<int, bool> maxzero(vector<vector<int>> matrix)
{   
    int msize = matrix.size();

    int maxnum = 0;
    bool isrow = true;
    int counter;
    int ind = 0;

    for (int i=0; i<msize; ++i) {
        counter = 0;
        for (int j=0; j<msize; ++j) {
            if (matrix[i][j] == 0) ++counter;
        }

        if (maxnum < counter) {
            maxnum = counter;
            ind = i;
        }

    }

    for (int i=0; i<msize; ++i) {
        counter = 0;
        for (int j=0; j<msize; ++j) {
            if (matrix[j][i] == 0) ++counter;
        }
        if (maxnum < counter) {
            maxnum = counter;
            ind = i;
            isrow = false;
        }
    }
    return make_pair(ind, isrow);
}