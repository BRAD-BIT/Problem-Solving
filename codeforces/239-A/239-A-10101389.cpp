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
    ll y, k, n; cin >> y >> k >> n; ll x = 1; bool test = true;
    while (1)
    {
        if (x*k - y > 0 && x*k <= n){ cout << x*k - y << " "; test = false; }
        if (x*k > n)break;
        x++;
    }
    if (test)cout << -1;
    cout << endl;
}