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
    ll x, y, z, k; cin >> x >> y >> k; z = abs(x) + abs(y);
    if ((z==k)||(z<k&&z%2==0&&k%2==0)||(z<k&&z%2!=0&&k%2!=0))cout << "YES" << endl; else cout << "NO" << endl;
}