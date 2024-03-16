#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string str = "Cumhuriyetin100.YiliKutluOlsun";

    wofstream outfile("soru1.txt");

    for (auto it=str.begin(); it!=str.end(); ++it) 
    {
        for (auto it2=str.begin(); it2!=it+1; ++it2) {
            outfile << *it2;
        }
        outfile << "\n";
    }

    for (auto it=str.end()-2; it!=str.begin()-1; --it) 
    {
        for (auto it2=str.begin(); it2!=it+1; ++it2) {
            outfile << *it2;
        }
        outfile << "\n";
    }

    outfile.close();

    return 0;
}