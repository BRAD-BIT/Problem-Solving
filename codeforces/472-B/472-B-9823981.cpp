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
#include<fstream>
using namespace std;
int main()
{
    int n, k, sum = 0; cin >> n >> k; int *a = new int[n], z = k, z1 = k; for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);
    int m = n-1;
    while (m>=0)
    {
        sum += 2*(a[m]-1);
        m -= k;
    }
    cout << sum << endl;
}