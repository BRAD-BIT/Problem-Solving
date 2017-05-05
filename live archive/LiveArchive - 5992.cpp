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
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
char grid[MAX][MAX];
int dis[MAX][MAX];
int R,C;vii pos;
void bfs()
{
	queue<ii>q;
	lop(i,0,sz(pos))q.push(pos[i]),dis[pos[i].first][pos[i].second]=0;pos.clear();
	ii cur;int dep;
	while(!q.empty())
	{
		while(!q.empty())
		{
			int iii=q.front().first,jjj=q.front().second;
			if(grid[iii][jjj]>='a'&&grid[iii][jjj]<='z')
				pos.push_back(ii(iii,jjj));
			q.pop();
		}
		lop(k,0,sz(pos))
		{
			cur=pos[k],dep=dis[cur.first][cur.second];
			lop(j,0,4)
			{
				int X=cur.first+dr[j];int Y=cur.second+dc[j];
				if(!(X<R&&X>=0&&Y>=0&&Y<C))continue;
				if(grid[X][Y]=='*'||grid[X][Y]=='#')continue;
				if(dis[X][Y]==dep+1&&grid[X][Y]!=grid[cur.first][cur.second]){grid[X][Y]='*';continue;}
				if(dis[X][Y]!=-1)continue;
				dis[X][Y]=dep+1;	
				q.push(ii(X,Y));grid[X][Y]=grid[cur.first][cur.second];
			}
		}
		pos.clear();
	}
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		cin>>R>>C;
		memset(dis,-1,sizeof dis);
		lop(i,0,R)lop(j,0,C){cin>>grid[i][j];if(grid[i][j]>='a'&&grid[i][j]<='z')pos.push_back(ii(i,j));}
		bfs();
		lop(i,0,R){lop(j,0,C)cout<<grid[i][j];cout<<endl;}
		cout<<endl;
	}
}