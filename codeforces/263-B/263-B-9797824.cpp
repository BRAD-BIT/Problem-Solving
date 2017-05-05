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
    int n, k; cin >> n >> k; long long *a = new long long[n + 1]; a[0] = 0; for (int i = 1; i <= n; i++)cin >> a[i]; sort(a, a + n + 1);
    if (n<k)cout << -1;
    else
    cout << a[n - k+1] <<" "<< a[n - k+1] << endl;
}