#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;  // soruda verilen 'pg45631.txt' yok. o yuzden 'soru1.txt' kullanildi

int main()
{
    ifstream infile("soru1.txt");

    if (!infile.is_open()) cerr << "cannot open the file!\n";

    string str, temp;

    while (getline(infile, temp)) {
        str.append(temp + "\n");
    }
    infile.close();

    int maxlower = 0;
    char maxlowerletter;

    for (int i='a'; i<='z'; ++i) {

        if (count(str.begin(), str.end(), (char) i) > maxlower) {
            maxlower = count(str.begin(), str.end(), (char) i);
            maxlowerletter = i;
        }
    }

    int maxupper = 0;
    char maxupperletter;

    for (int i='A'; i<='Z'; ++i) {

        if (count(str.begin(), str.end(), (char) i) > maxupper) {
            maxupper = count(str.begin(), str.end(), (char) i);
            maxupperletter = i;
        }
    }

    int maxother = 0;
    char maxotherchar;

    for (int i=33; i<=255; ++i) {
        if (i == 'a' || i == 'A') i += 25;
        if (count(str.begin(), str.end(), (char) i) > maxother) {
            maxother = count(str.begin(), str.end(), (char) i);
            maxotherchar = i;
        }
    }

    cout << maxlower << " tane " << maxlowerletter << " harfi\n";
    cout << maxupper << " tane " << maxupperletter << " harfi\n";
    cout << maxother << " tane " << maxotherchar << " harfi\n";

    return 0;
}
