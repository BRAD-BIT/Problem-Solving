//In the name of Allah
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
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("easy.in"),W_("easy.out")
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
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int a[MAX], b[MAX];
ll power(ll b, ll p)
{
    ll mul = b, ret = 1;
    while (p)
    {
        if (p & 1)ret = (ret*mul);
        mul = (mul*mul);p >>= 1;
    }
    return ret;
}
int main()
{
    ll n, k, ans = 1; cin >> n >> k;
    lop(i, 0, n / k)cin >> b[i];
    lop(i, 0, n / k)cin >> a[i];
    lop(i, 0, n / k)
    {
        ll x = a[i] * power(10, k - 1), y = x, z = 9 * power(10, k - 1), w = 0;
        lop(j, 0, k - 1)y += 9 * power(10, j), z += 9 * power(10, j);
        w = (z / b[i]) - (y / b[i]) + ((x - 1) / b[i])*(x != 0)+(a[i]!=0);
        ans = (ans*w) %MOD;
    }
    cout << ans << endl;
}