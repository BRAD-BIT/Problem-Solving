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
    string x; cin >> x; long long z = x.length();
    for (int i = 0; i < z; i++)
    {
        if (i==0&&x[i]!='9')
        {
            if (9 - (x[i] - 48) < (x[i] - 48))x[i] = (9 - (x[i] - 48)) + 48;
        }
        else
        if (i != 0){ if (9 - (x[i] - 48) < (x[i] - 48))x[i] = (9 - (x[i] - 48)) + 48; }
    }
    cout << x << endl;
}