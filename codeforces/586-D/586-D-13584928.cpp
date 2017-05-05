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
int dr[] = { 0, 1, -1, -1, -1, -1, 1, 1 };
int dc[] = { 1, 1, 1, 0, -1, 1, -1, 1 };
int const MAX = 100 + 7;
int const MOD = 1e9 + 7;
struct train{int start,end,row;};
train t[MAX];int n,k,x;char grid[3][MAX];
bool can_move(int r,int c,int dep,int type)
{
    dep*=2;
    lop(i,0,k)
    {
        if(r!=t[i].row)continue;
        if((c>t[i].end-dep||c<t[i].start-dep)&&(c>t[i].end-(dep+2)||c<t[i].start-(dep+2)||type))continue;
        return 0;
    }
    return 1;
}
int valid;int mem[4][200][200];
int DFS(int r,int c,int dep)
{
    if(2*dep>=x){return 1;}
    if(mem[r][c][dep]!=-1)return mem[r][c][dep];
    int ans1=0,ans2=0,ans3=0;
    if(r+1<3&&c+1<n)if(can_move(r,c+1,dep,1)&&can_move(r+1,c+1,dep,0))ans1=DFS(r+1,c+1,dep+1);
    if(r-1>=0&&c+1<n)if(can_move(r,c+1,dep,1)&&can_move(r-1,c+1,dep,0))ans2=DFS(r-1,c+1,dep+1);
    if(c+1<n)if(can_move(r,c+1,dep,0))ans3=DFS(r,c+1,dep+1);
    mem[r][c][dep]=ans1|ans2|ans3;
}
int main()
{
    //R_W;
    int T;cin>>T;
    while(T--)
    {
        cin>>n>>k;
        lop(i,0,3)lop(j,0,n)cin>>grid[i][j];grid[0][n]=grid[1][n]=grid[2][n]='*';
        ii S;int p=0;x=0;
        lop(i,0,3){
            lop(j,0,n){
                if(grid[i][j]=='s'){S=ii(i,j);continue;}
                if(grid[i][j]=='.')continue;
                int s=j,e;char c=grid[i][j];
                for(int z=j;z<=n;z++,j++)if(grid[i][z+1]!=c){e=z;break;}
                t[p].start=s,t[p].end=e,t[p++].row=i;x=max(x,e+1);
            }
        }
        memset(mem,-1,sizeof mem);
        if(DFS(S.first,S.second,0))cout<<"YES\n";else cout<<"NO\n";
    }
}