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
int arr[100];
int graph1[333][333],vis[333],prv[333];
vvi graph2;
int max_flow(int s,int t)
{
	int mf = 0; --s, --t;
	while (1)
	{
		queue<int>q; q.push(s); memset(vis, 0, sizeof vis); memset(prv, -1, sizeof prv);
		vis[s] = 1;
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int i = 0; i < graph2[cur].size(); i++)
			{
				int child = graph2[cur][i];
				if (!vis[child] && graph1[cur][child]>0)
				{
					vis[child] = 1; prv[child] = cur; q.push(child); if (child == t)goto NEXT;
				}
			}
		}
	NEXT:
		vector<int>path;
		if (prv[t] == -1)return mf;
		int i = t;
		path.push_back(t);
		while (prv[i] != s)
		{
			path.push_back(prv[i]);
			i = prv[i];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		int mn = oo;
		for (int i = 0; i < path.size() - 1; i++)mn = min(mn, graph1[path[i]][path[i + 1]]);
		for (int i = 0; i < path.size() - 1; i++)
		{
			graph1[path[i]][path[i + 1]] -= mn;
			graph1[path[i + 1]][path[i]] += mn;
		}
		mf += mn;
	}
}
struct circle
{
	int x,y,r;ld f;
	circle(int xx,int yy,int rr,ld ff):x(xx),y(yy),r(rr),f(ff){};
	bool is_intersect(circle c)
	{
		int d=(c.x-x)*(c.x-x)+(c.y-y)*(c.y-y);
		if((c.r+r)*(c.r+r)<d)return 0;
		return 1;
	}
};

int main()
{
	int t;cin>>t;
	lop(T,0,t)
	{
		int n;cin>>n;vector<circle>p;int s,t;graph2.resize(n);
		lop(i,0,n)
		{
			int x,y,r;ld f;cin>>f>>x>>y>>r;
			p.push_back(circle(x,y,r,f));
			 if(f==400.0)s=i;
             if(f==789.0)t=i;
		}
		memset(graph1,0,sizeof graph1);
		lop(i,0,n)
			lop(j,0,n)
			if(p[i].is_intersect(p[j])&&p[i].f<p[j].f)
				graph1[i][j]=1,graph2[i].push_back(j),graph2[j].push_back(i);

		int M=max_flow(s+1,t+1);
		if(M>=2)cout << "Game is VALID" << endl;
        else cout << "Game is NOT VALID" << endl;
		//cout<<M<<endl;
		graph2.clear();
		p.clear();
	}
}