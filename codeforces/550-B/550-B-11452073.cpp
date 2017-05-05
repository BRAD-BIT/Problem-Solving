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
struct A3{ int sum1 = 0, sum2 = 0, max = 0, min = 100000000; };
int main()
{
    int n, l, r, y, ans = 0; int a[17]; 
    cin >> n >> l >> r >> y;
    for (int i = 0; i < n; i++){ cin >> a[i]; }
    ll m = pow(2.0000, double(n));
    for (int i = 0; i < m; i++)
    {
        bitset<16>s(i); A3 x;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 1){ x.sum2++; x.sum1 += a[j]; x.max = max(x.max, a[j]); x.min = min(x.min, a[j]); }
        }
        if (x.sum2 >= 2 && x.sum1 >= l&&x.sum1 <= r && (x.max - x.min) >= y)ans++;
    }
    cout << ans << endl;
}