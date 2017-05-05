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
struct unhappy{int stat,index;};
int main()
{
    int n, m; cin >> n >> m; int z;
    if (n == m)z = n;
    else 
    if (m > n){ z = m; int o = 2; while (z%n != 0){ z = o*m; o++; } }
    else 
    if (m < n){ z = n; int o = 2; while (z%m != 0){ z = o*n; o++; } }
    unhappy *a = new unhappy[z], *b = new unhappy[z];
    int x = 0, y = 0;
    for (int i = 0; i < z; i++)
    {
        a[i].stat = 0;a[i].index = x; x++;if (x == n)x = 0;
        b[i].stat = 0;b[i].index = y; y++;if (y == m)y = 0;
    }
    cin >> x;
    for (int i = 0; i < x; i++){ cin >> y; for (int j = 0; j < z; j++){ if (a[j].index == y){ a[j].stat = 1; } } }
    cin >> x;
    for (int i = 0; i < x; i++){ cin >> y; for (int j = 0; j < z; j++){ if (b[j].index == y){ b[j].stat = 1; } } }
    for (int i = 0; i < z; i++)
    {
        if (a[i].stat == 1 && b[i].stat == 0)for (int j = 0; j < z; j++){ if (b[i].index == b[j].index){ b[j].stat = 1; a[j].stat = 1; } }
        else
        if (b[i].stat == 1 && a[i].stat == 0)for (int j = 0; j < z; j++){ if (a[i].index == a[j].index){ a[j].stat = 1; b[j].stat = 1; } }
    }
    for (int i = 0; i < z; i++)
    {
        if (a[i].stat == 0 || b[i].stat == 0){cout << "NO" << endl; return 0;}
    }
    cout << "YES" << endl;
}