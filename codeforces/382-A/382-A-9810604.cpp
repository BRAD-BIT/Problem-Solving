#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
    string s1, s2; cin >> s1 >> s2; int sumL, sumR, sumEXTRA = s2.length();
    for (int i = 0; i < s1.length(); i++){ if (s1[i] == '|'){ sumL = i; sumR = s1.length() - i - 1; } }
    string sR = s1;
    string sL = s1.erase(sumL, sumR+1);
    sR.erase(0, sumL + 1);
    int m = 0;
    while (sumEXTRA!=0)
    {
        if (sumL>sumR){ sumR++; sR += s2[m]; sumEXTRA--; m++; }
        else
        if (sumR > sumL){ sumL++; sL += s2[m]; sumEXTRA--; m++; }
        else { sumL++; sL += s2[m]; sumEXTRA--; m++; }
    }
    if (sumL != sumR)cout << "Impossible" << endl;
    else cout << sL << "|" << sR << endl;
}