#include<iostream>
#include<string>
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
    ll x, y, z, n; cin >> x >> y >> n; ll a[] = { x, y, y - x, -x, -y, -(y - x) };
    z = a[(n-1) % 6];
    if (z < 0)
    {
        while (z<0)
        {
            z += 1000000007;
        }
        cout << z;
    }
    else
        cout << z % 1000000007 << endl;
}