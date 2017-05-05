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
#define R_W        R_("in.txt"),W_("out.txt")
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
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
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
int const MAX = 10 + 7;
int const MOD = 1e9 + 7;
int vis[MAX][MAX];char grid[MAX][MAX];
int ans=0,n,m;
void DFS(int r,int c,int x)
{
    if(vis[r][c]>3)return;
    ans+=(vis[r][c]++==0);
    int vv=0;
    while(vv<4&&!(r+dr[x]!=0&&r+dr[x]<=n&&c+dc[x]!=0&&c+dc[x]<=m&&grid[r+dr[x]][c+dc[x]]=='.')){x++;x%=4;vv++;}
    if(vv>=4)return;
    DFS(r+dr[x],c+dc[x],x);
}
int main()
{
    cin>>n>>m;int x=2;ii pos;
    lop(i,0,MAX)lop(j,0,MAX)grid[i][j]='k';
    lop(i,1,n+1)lop(j,1,m+1){cin>>grid[i][j];
    if(grid[i][j]!='.'&&grid[i][j]!='*'){
        pos=ii(i,j);
        if(grid[i][j]=='U')x=2;
        if(grid[i][j]=='D')x=0;
        if(grid[i][j]=='R')x=3;
        if(grid[i][j]=='L')x=1;
        grid[i][j]='.';
    }
    }
    DFS(pos.first,pos.second,x);
    cout<<ans<<endl;
}