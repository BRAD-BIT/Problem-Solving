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
#include<string>
#include<cstdio>
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 4 * 1e5 + 7;
ll h, n;
ll calc(ll i)
{
    ll sum = 1, now = 1;
    lop(level, 1, h + 2)
    {
        if (i <= sum)return (pow(2.000, double(h + 1 - (level - 1))) - 2) / 2;
        now *= 2;
        sum += now;
    }
}
bool M(ll p)
{
    ll l = p, r = p;
    while (1)
    {
        if (n >= l&&n <= r)return 1;
        if (calc(l) == 0 || calc(r) == 0)return 0;
        l=2*l; r=2*r+1;
    }
}
ll solve(ll p,ll l)
{
    if (p == n)return 0;
    ll child_sum = calc(p);
    int is_left = M(2 * p);
    if (!is_left){ if (l)return solve(2 * p + 1, 1) + child_sum + 1; else return solve(2 * p + 1, 1) + 1; }
    if (l)return solve(2 * p, 0) + 1; else return solve(2 * p, 0) + 1 + child_sum;
}
int main()
{
    cin >> h >> n;
    n += (pow(2.000, double(h)) - 1);
    cout << solve(1,1) << endl;
}