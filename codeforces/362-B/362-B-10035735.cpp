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
    ll n, m; cin >> n >> m; int a[3000]; for (int i = 0; i < m; i++){ cin >> a[i]; if (a[i] == 1 || a[i] == n){ cout << "NO" << endl; return 0; } }sort(a, a + m);
    for (int i = 0; i < m - 2; i++)
    {
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]){ cout << "NO" << endl; return 0; }
    }
    cout << "YES" << endl;
}