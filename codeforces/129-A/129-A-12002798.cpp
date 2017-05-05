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

using namespace std;
int main()
{
    int n, sum1 = 0, sum2 = 0; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++){ cin >> a[i]; sum1 += a[i]; }
    for (int i = 0; i < n; i++)
    {
        sum1 -= a[i];
        if (sum1 % 2 == 0)sum2++;
        sum1 += a[i];
    }
    cout << sum2;
}