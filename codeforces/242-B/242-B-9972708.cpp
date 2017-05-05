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
struct point{ ll start, end; };
int main()
{
    ll n, min = 1000000000, max = 0; cin >> n; point *a = new point[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].start >> a[i].end;
        if (min > a[i].start)min = a[i].start;
        if (max < a[i].end)max = a[i].end;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].start == min&&a[i].end == max){ cout << i + 1 << endl; return 0; }
    }
    cout << -1 << endl;
}