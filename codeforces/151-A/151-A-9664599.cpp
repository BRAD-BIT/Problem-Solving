#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int a = k*l;
    int b = c*d;
    int v = a / nl;
    int r = p / np;
    int u[] = { r, v, b };
    int min = u[0];
    for (int i = 0; i < 3; i++)
    {
        if (u[i] < min)min = u[i];
    }
    cout << min / n;
}