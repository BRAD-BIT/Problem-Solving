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
#include<vector>
#include<map>
#include<set>
#include <stdio.h>
using namespace std;
int main()
{
    int n, m; bool test = false; cin >> n >> m; int *a = new int[n]; int *b = new int[m]; for (int i = 0; i <n; i++)cin >> a[i]; for (int i = 0; i <m; i++)cin >> b[i];
    sort(a, a + n); sort(b, b + m); for (int i = 0; i < n; i++){ if (2 * a[i] <= a[n - 1]){ test = true; break; } }
    if (a[n - 1] >= b[0])cout << -1;
    else
    {
        if (test)cout << a[n - 1];
        else
        {
            if (a[0] * 2 < b[0])cout << 2*a[0];
            else cout << -1;
        }
    }
}