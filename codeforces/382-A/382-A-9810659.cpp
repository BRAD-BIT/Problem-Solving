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
    string s1, s2,sR,sL; cin >> s1 >> s2;
    sL = s1.substr(0, s1.find('|'));
    sR = s1.substr(s1.find('|') + 1, s1.length());
    int sumL = sL.length(), sumR = sR.length(), sumEXTRA = s2.length(), m = 0;
    while (sumEXTRA!=0)
    {
        if (sumL>sumR){ sumR++; sR += s2[m]; sumEXTRA--; m++; }else if (sumR > sumL){ sumL++; sL += s2[m]; sumEXTRA--; m++; }else { sumL++; sL += s2[m]; sumEXTRA--; m++; }
    }
    if (sumL != sumR)cout << "Impossible" << endl;
    else cout << sL << "|" << sR << endl;
}