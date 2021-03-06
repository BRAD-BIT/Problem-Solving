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
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ld,ld>
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
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 2*1e6 + 7;
int const MOD = 1e9 + 7;
ll fact[MAX];
ll power_log(ll b, ll p){
    ll mul = b, ret = 1;
    while (p){if (p & 1)ret = (ret*mul) % MOD;mul = (mul*mul) % MOD;p >>= 1;}
    return ret;
}
ll NCR(ll n, ll r){
    ll ret = fact[n] * power_log(fact[r], MOD - 2);
    ret = (ret%MOD)*power_log(fact[n - r], MOD - 2);
    return ret;
};
int main()
{
    int n;
    while (cin >> n)
    {
        ll ans = power_log(2, n + 1) - 1, cur = power_log(2, n), not_have_2_child;
        fact[0]=fact[1] = 1;
        lop(i, 2, 2 * n + 1){ fact[i] = ((i%MOD)*(fact[i - 1] % MOD)) % MOD; }
        lop(i, 0, n)
        {
            not_have_2_child = 2 * NCR(n+i,n); not_have_2_child %= MOD;
            cur = 2 * (cur - not_have_2_child+MOD) + not_have_2_child; cur%=MOD;
            ans += cur; ans %= MOD;
        }
        cout << ans << endl;
    }
}