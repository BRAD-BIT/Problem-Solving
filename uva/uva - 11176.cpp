#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(ll i=a;i<n;++i)
#define loop(i,n,a)for(ll i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define sz(v)      (ll)v.size()
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr4(n)     printf("%lld\n",n)
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS pow(10,-9)
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 500 + 7;
const int MOD = 1e9 + 7;
ld p; int n;
ld ans[MAX][MAX];
ld power_log(ld b, ll p) {
    ld mul = b, ret = 1;
    while (p) {
        if (p & 1)ret = (ret*mul);
        mul = (mul*mul);
        p >>= 1;
    }
    return ret;
}
ld solve()
{
    memset(ans, 0, sizeof ans);
    lop(i, 0, n+1)lop(j, i, n+1)ans[i][j] = 1;
    lop(i, 1, n+1)ans[i][i - 1] = 1 - power_log(p, i);
    lop(i, 1, n+1)lop(j, 0, i-1)ans[i][j] = ans[i - 1][j] - ans[i - j - 2][j] * (1 - p)*power_log(p, j + 1);
    ld ret = 0;
    lop(i, 0, n+1)ret += (ans[n][i] - ans[n][i-1])*i;
    return ret;
}
int main()
{
    while ((cin >> n >> p)&&n) {
        pr3(solve());
    }
}