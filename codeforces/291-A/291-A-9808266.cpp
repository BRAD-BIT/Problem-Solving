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
    int n, sum1 = 1, sum2 = 0; cin >> n; long long *a = new long long[n]; for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])sum1++;
        else
        {
            if (sum1>2&&a[i]!=0){ cout << -1 << endl; return 0; }
            if (sum1 == 2&&a[i]!=0)sum2++;
            sum1 = 1;
        }
    }
    cout << sum2 << endl;
}