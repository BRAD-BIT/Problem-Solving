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
    long long k, l; cin >> k >> l; double i = 1;
    while (true)
    {
        long long z = pow(k, i);
        if (z == l){ cout << "YES" << endl << i - 1 << endl; return 0; }
        if (z > l){ cout << "NO" << endl; return 0; }
        i++;
    }
}