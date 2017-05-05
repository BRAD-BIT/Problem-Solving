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
int const MAX = 1e5 + 7;
int const mod = 1e9 + 7;
vvi G; int f = -1; map<int, int>mp, mp2;int vis[MAX];
void DFS(int node,int print)
{
    vis[node] = 1;
    lop(i, 0, sz(G[node]))
    {
        int child = G[node][i];
        if (!vis[child])DFS(child,print);
    }
    if (print)pr2(mp2[node]);
    if (f == -1)f = node;
}
int main()
{
    int n, m = 1; sc(n); G.resize(n+1);
    lop(i, 0, n)
    {
        int a, b; sc(a), sc(b); if (!mp[a])mp[a]=m++,mp2[m-2]=a;if(!mp[b])mp[b]=m++,mp2[m-2]=b;
        a = mp[a]-1; b = mp[b]-1;G[a].push_back(b); G[b].push_back(a);
    }
    memset(vis, 0, sizeof vis);
    DFS(0,0);
    memset(vis, 0, sizeof vis);
    DFS(f,1);
    cout << endl;
}