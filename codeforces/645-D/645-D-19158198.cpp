//In the name of Allah
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
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
vvii G;
ii mem[MAX];
ii mx(ii a, ii b)
{
    if (a.first == b.first)return ii(a.first, min(a.second, b.second));
    if (a.first < b.first)return b;
    return a;
}
ii DFS(int node)
{
    if (mem[node].first != -1)return mem[node];
    ii ret(0, 0);
    lop(i, 0, sz(G[node]))
    {
        ii child = G[node][i];
        ii r = DFS(child.first);
        r.second = max(child.second, r.second);
        ret = mx(r, ret);
    }
    return mem[node] = ii(ret.first + 1, ret.second);
}
int main()
{
    int n, m;
    cin >> n >> m;
    G.resize(n);
    lop(i, 0, n)mem[i].first = -1;
    lop(i, 0, m)
    {
        int x, y; cin >> x >> y;
        G[--x].push_back(ii(--y, i));
    }
    ll ans = OO;
    lop(i, 0, n) { ii r = DFS(i); if (r.first == n)ans = min(r.second, ans); }
    if (ans == OO)
        cout << "-1\n";
    else
    cout << ans+1 << endl;
}