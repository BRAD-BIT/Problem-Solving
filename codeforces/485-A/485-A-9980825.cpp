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
    ll a, m; cin >> a >> m; ll  z = m;
    while (z != 0)
    {
        if (a%m == 0){ cout << "Yes" << endl; return 0; }
        else a += a%m;
        z--;
    }
    cout << "No" << endl;
}