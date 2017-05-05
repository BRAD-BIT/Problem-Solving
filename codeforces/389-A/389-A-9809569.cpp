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
    int n, sum = 0; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);
    while (a[n - 1] != a[0])
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1]>a[i])a[i + 1] -= a[i];
        }
        sort(a, a + n);
    }
    for (int i = 0; i < n; i++){ sum += a[i]; }
    cout << sum << endl;
}