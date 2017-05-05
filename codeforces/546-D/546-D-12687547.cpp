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
int const MAX = 5*1e6 + 7;
int const MOD = 1e9 + 7;
ll mp[MAX];ll sum[MAX];
void prime_factors(int n)
{
    int num = n, ans = 0;
    while (num % 2 == 0)
    {
        ans++; num /= 2; if (mp[num]){ mp[n] = ans + mp[num]; return; }
    }
    for (int pf = 3; pf*pf <= n;pf+=2)
    {
        while (num%pf == 0)
        {
            ++ans; num /= pf;
            if (mp[num]){ mp[n] = ans + mp[num]; return; }
        }
    }
    if (num > 1)++ans;
    mp[n] = ans;
}
int main()
{
    lop(i, 2, 5000007)prime_factors(i);
    lop(i, 0, 5000007)
    {
        sum[i] = mp[i]; if (i)sum[i] += sum[i - 1];
    }
    int q; sc(q);
    lop(i, 0, q)
    {
        int a, b; sc(a), sc(b);
        pr1(sum[a] - sum[b]);
    }
}