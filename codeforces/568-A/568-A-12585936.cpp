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
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#include<string>
#include<cstdio>
using namespace std;
#define iter(it,S) for(set<int>::iterator it = S.begin(); it != S.end(); ++it)
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
int const MAX = 1e7 + 7;
int const MOD = 1e9 + 7;
vi is_prime;
void Prime_Sieve(ll n)
{
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 0; i*i <= n; i++)
        if (is_prime[i])
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = 0;
}
bool is_pal(ll n)
{
    ll m = 0,o = n;
    while (o){ m = m * 10 + o % 10; o /= 10; }
    return m == n;
}
int main()
{
    Prime_Sieve(10000000); 
    ll a = 0, b = 0, ans = -1; ld p, q; cin >> p >> q; p /= q;
    lop(i, 1, 10000001)
    {
        if (is_prime[i])++a;
        if (is_pal(i))++b;
        if (a <= b*p)ans = i;
    }
    if (ans == -1)return(cout << "Palindromic tree is better than splay tree", 0);
    cout << ans << endl;
}