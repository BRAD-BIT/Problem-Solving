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
ll n; ll a[1000005]; ll mem[2][1000005];ll Max=0;
ll dp(int i,int last)
{
    if (i == Max + 1)return 0;
    if (mem[last][i]!=-1)return mem[last][i];
    ll ans1 = 0, ans2;
    if (!last && a[i] != 0) ans1 = dp(i + 1, 1) + a[i] * i;
    ans2 = dp(i + 1, 0);
    return mem[last][i] = max(ans1, ans2);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){ ll x; cin >> x; a[x]++;Max=max(Max,x); }
    memset(mem,-1,sizeof mem);
    ll ans = dp(1, 0);
    cout << ans << endl;
}