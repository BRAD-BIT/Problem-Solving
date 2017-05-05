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
    ll a[21] = { 0 }; int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x < 0)a[abs(x)]++;
        if (x > 0)a[x + 10]++;
        if (x == 0)a[0]++;
    }
    ll sum = (a[0]*(a[0]-1))/2;
    for (int i = 1; i <= 10; i++)sum += (a[i] * a[i + 10]); cout << sum << endl;
}