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
    int n, d, m, sum = 0; cin >> n >> d; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i]; cin >> m;
    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        if (i >= n){ sum -= d; }
        else sum += a[i];
    }
    cout << sum << endl;
}