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
vi fac, com_div;
int bs(int l,int r)
{
    int s = 0, e = sz(com_div)-1, mid, ans = -1;
    while (s <= e)
    {mid = (s + e) / 2;
    if (com_div[mid] > r){e = mid - 1;}
    else{if (com_div[mid] >= l)ans = com_div[mid];s = mid + 1;}}
    return ans;
}
int main()
{
    int a, b; cin >> a >> b; map<int, int>mp; 
    for (int i = 1; i*i <= a; ++i)
    {
        int x = i, y = a / i;
        if (a%x == 0)if (!mp[x]){ mp[x] = 1; fac.push_back(x); }
        if (a%y == 0)if (!mp[y]){ mp[y] = 1; fac.push_back(y); }
    }
    lop(i, 0, sz(fac)){ if (b%fac[i]==0)com_div.push_back(fac[i]); }
    sort(all(com_div));
    int q; sc(q);
    lop(i, 0, q)
    {
        int x, y; sc(x), sc(y);
        pr1(bs(x, y));
    }
}