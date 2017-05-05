#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int n; cin >> n; int minz = 1;
    while (1)
    {
        n -= minz; minz++;
        if (n == 0){ cout << "YES" << endl; return 0; }
        if (n<0){ cout << "NO" << endl; return 0; }
    }
}