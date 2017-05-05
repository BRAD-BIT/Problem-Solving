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
    int n; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i]; sort(a, a + n);
    int x = a[0]; int max = 0, sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == x)sum++;
        else
        {
            if (sum>max)max = sum; sum = 1; x = a[i];
        }
    }
    if (max > ceil(n / 2.00))cout << "NO" << endl; else cout << "YES" << endl;
}