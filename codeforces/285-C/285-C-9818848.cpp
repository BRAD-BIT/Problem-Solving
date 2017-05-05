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
    long long n, sum = 0; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        sum += abs(i + 1 - a[i]);
    }
    cout << sum << endl;
}