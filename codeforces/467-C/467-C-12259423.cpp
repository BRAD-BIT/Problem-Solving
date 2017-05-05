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

#define lop(i,n)   for(ll i=0;i<n;++i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define ld         long double
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
ll mod = 1e9 + 7;
const int MAX = 5000 + 100;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
ii arr[MAX]; ll mem[MAX][MAX];
int n, m, k; 
ll dp(int i,int rem)
{
    if (i >= n)
    {
        if (rem != 0)return -100000000000000;
        return 0;
    }
    if (mem[i][rem] != -1)return mem[i][rem];
    ll ans1 = dp(i + 1, rem);
    ll ans2 = 0;
    if (rem>0&&i+m-1<n)ans2=dp(i + m, rem - 1) + (arr[i + m - 1].second - arr[i].second + arr[i].first);
    return mem[i][rem] = max(ans1, ans2);
}
int main()
{
    cin >> n >> m >> k;
    lop(i, n){ cin >> arr[i].first; arr[i].second = arr[i].first; if (i)arr[i].second += arr[i - 1].second; }
    memset(mem, -1, sizeof mem);
    ll ans = dp(0, k);
    cout << ans << endl;
}