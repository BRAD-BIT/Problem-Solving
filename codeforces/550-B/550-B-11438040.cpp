#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<functional>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<int>v1;
vector<int>v2;
vector<int>v3;
ll n, l, r, x; ll a[17]; ll ans = 0;
void dp(ll i, ll sum1, ll sum2, ll min1, ll max1)
{
    if (i == n)
    {
        if (sum2 >= 2 && sum1 >= l&&sum1 <= r && (max1 - min1) >= x)ans++; return;
    }

    ll min2 = min(min1, a[i]);
    ll max2 = max(max1, a[i]);

    dp(i + 1, sum1 + a[i], sum2 + 1, min2, max2);
    dp(i + 1, sum1, sum2, min1, max1);
}
int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)cin >> a[i];
    dp(0, 0, 0, 10000000000, 0);
    cout << ans << endl;
}