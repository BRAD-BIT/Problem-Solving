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
    int  n, k; cin >> n >> k; int a[100007]; for (int i = 0; i < n; i++)cin >> a[i]; int pos=1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[n - 1] != a[i]){ pos = i + 2; break; }
    }
    if (k >= pos)cout << pos - 1 << endl;
    else cout << -1 << endl;
}