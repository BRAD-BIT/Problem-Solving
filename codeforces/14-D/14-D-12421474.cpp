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
const int MAX = 200 + 7;
vvi G; ii not; int vis[MAX]; ii cur_dep;
void DFS(int node, int dep)
{
    if (dep > cur_dep.first){ cur_dep.first = dep; cur_dep.second = node; }
    vis[node] = 1;
    lop(i, 0, sz(G[node]))
    {
        int child = G[node][i];
        if (ii(node, child) == not || ii(child, node) == not || vis[child])continue;
        DFS(child, dep + 1);
    }
}
int longest(int i)
{
    cur_dep=ii(0, i);
    memset(vis, 0, sizeof vis);
    DFS(i, 0);
    ii temp = cur_dep; cur_dep = ii(0, temp.second);
    memset(vis, 0, sizeof vis);
    DFS(temp.second, 0);
    return cur_dep.first;
}
int main()
{
    int n,a, b, ans = 0; sc(n); G.resize(n);
    lop(i, 0, n-1)
    {
        sc(a), sc(b); G[--a].push_back(--b); G[b].push_back(a);
    }
    lop(i, 0, n)
    {
        lop(j, 0, sz(G[i]))
        {
            not = ii(i, G[i][j]);
            int pathA = longest(i), pathB = longest(G[i][j]);
            ans = max(ans, longest(i)*longest(G[i][j]));
        }
    }
    pr1(ans);
}