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
//#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
//#include<array>
#include<string>
#include<cstdio>
using namespace std;
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
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const mod = 1e9 + 7;
ll a, b, n, NR[MAX];
int isgood(ll x)
{
    while (x){if (x % 10 != a && x % 10 != b) return 0;x /= 10;}
    return 1;
}
ll f(ll b, ll p){
    if (p == 1) return b;
    if (p % 2 == 0) return f((b*b) % mod, p / 2);
    return (f(b, p - 1)*b) % mod;
}
int main(){
    NR[0] = 1;
    ll ans = 0; scl(a), scl(b), scl(n);
    lop(i,1,n+1)NR[i] = (((NR[i - 1] * (n - i + 1)) % mod) * f(i, mod - 2)) % mod;
    lop(i,0,n+1){if (isgood(a*i + b*(n - i))){ans = (ans + NR[i]) % mod;}}
    cout << ans << endl;
}