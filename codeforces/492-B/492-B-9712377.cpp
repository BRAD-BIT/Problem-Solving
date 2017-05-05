#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
using namespace std;
int main()
{
    long long  n, l;
    cin >> n >> l;
    long long *a = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x = a[0];
    long long y = l - a[n - 1];
    double diff = 0;
    for (int i = 0; i < n-1; i++)
    {
        if ((a[i + 1] - a[i]) / 2.0000>diff)diff = (a[i + 1] - a[i]) / 2.0000;
    }
    if (diff > x&&diff > y) cout << fixed << setprecision(10) << diff;
    else
    if (x > y&&x > diff/2.000)cout << x;
    else cout << y;
}