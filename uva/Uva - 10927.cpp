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
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ld,ld>
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
#define pr3(n)     cout<<fixed<<setprecision(4)<<n<<endl
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
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
struct point
{
	ld x, y, z;
	point(){ x = y = z = 0.0; }
	point(ld xx, ld yy, ld zz) :x(xx), y(yy),z(zz){}
	static ld dis(point p1){ return sqrt((p1.x)*(p1.x) + (p1.y)*(p1.y)); }
};
bool comp(point p1, point p2){return point::dis(p1) < point::dis(p2);}
bool comp2(ii p1, ii p2){if (p1.first==p2.first)return p1.second < p2.second;return p1.first < p2.first;}
vector<ii>xxx;
void solve(vector<point>vec,int x)
{
	if (!sz(vec))return;
	map<ld, int>mp; int j = 0;
	vector<vector<point>>vv(sz(vec));
	if (x)
	{
		j++;
		lop(i, 0, sz(vec))vv[0].push_back(vec[i]);
	}
	if (!x)
	lop(i, 0, sz(vec))
	{
		ld m = vec[i].y / vec[i].x;
		if (!mp[m])mp[m] = ++j;
		vv[mp[m] - 1].push_back(vec[i]);
	}
	lop(i, 0, j){
		sort(all(vv[i]), comp); int m = -5;
		lop(k, 0, sz(vv[i]))
			if (vv[i][k].z > m)m = vv[i][k].z; else xxx.push_back(ii(vv[i][k].x, vv[i][k].y));
	}
}
vector<point>p[10];
int main()
{
	point M; int n, t = 1;
	while (1)
	{
		sc(n); if (n == 0)break;
		lop(i, 0, n)
		{
			ld x, y, z; int j=8;
			cin >> x >> y >> z;
			if (y == 0)if (x > 0)j = 0;else j = 1;
			if (x == 0)if (y > 0)j = 2; else j = 3;
			if (x > 0 && y > 0)j = 4; if (x > 0 && y < 0)j = 5;
			if (x < 0 && y > 0)j = 6; if (x < 0 && y < 0)j = 7;
			p[j].push_back(point(x, y, z));
		}
		lop(i, 0, 4)solve(p[i], 1);
		lop(i, 4, 8)solve(p[i], 0);
		cout << "Data set " << t++ << ":\n";
		if (xxx.size() != 0)
		{
			sort(all(xxx), comp2);
			cout << "Some lights are not visible:\n";
			lop(i, 0, sz(xxx) - 1)cout << "x = " << xxx[i].first << ", y = " << xxx[i].second << ";\n";
			cout << "x = " << xxx[sz(xxx)-1].first << ", y = " << xxx[sz(xxx)-1].second << ".\n";
		}
		else
		cout << "All the lights are visible.\n";
		xxx.clear();
		lop(i, 0, 8)p[i].clear();
	}
}