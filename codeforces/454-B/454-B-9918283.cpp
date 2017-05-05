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
    int n; cin >> n; int *a = new int[n], *b = new int[n]; for (int i = 0; i < n; i++){ cin >> a[i]; b[i] = a[i]; }
    sort(b, b + n);
    int v = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])v = i + 1;
    }
    if (v == -1){cout << 0; return 0;}
    for (int i = v; i < n; i++)
    {
        if (a[i] != b[i - v]){cout << -1 << endl; return 0;}
    }
    for (int i = 0; i < v; i++)
    {
        if (a[i] != b[n-v+i]){ cout << -1 << endl; return 0; }
    }
    cout << (n - v) << endl;
}