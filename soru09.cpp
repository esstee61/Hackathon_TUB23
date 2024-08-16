#include <iostream>
#include <vector>

using namespace std;

bool canCross(vector<int> v, int i, int j);

int main() 
{   
    vector<int> nums = {0, 1, 3, 5, 6, 8, 12, 17};

    cout << canCross(nums, 0, 0) << '\n';
    
    vector<int> nums2 = {0, 1, 2, 3, 4, 8, 9, 11};

    cout << canCross(nums2, 0, 0) << '\n';
    return 0;
}

bool canCross(vector<int> v, int i, int j)
{   
    int n = v.size();
    if (v[n-1] <= v[i] + j + 1 && v[n-1] >= v[i] + j - 1) {
        return true;
    }   

    int x = 1;
    while (v[i+x] <= v[i] + j + 1 && v[i+x] >= v[i] + j - 1) {
        if (canCross(v, i+x, v[i+x] - v[i])) return true;
        ++x;
    }
    return false;
}
