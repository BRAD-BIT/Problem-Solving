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
ll a[100000]; ll b[100000]; ll c[100000];
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n - 1; i++)cin >> b[i];
    for (int i = 0; i < n - 2; i++)cin >> c[i];
    sort(a, a + n);
    sort(b, b + n - 1);
    sort(c, c + n - 2);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i]){ cout << a[i] << endl; break; }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] != c[i]){ cout << b[i] << endl; break; }
    }
}