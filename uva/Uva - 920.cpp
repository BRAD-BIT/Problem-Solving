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
#define pr3(n)     cout<<fixed<<setprecision(2)<<n<<endl
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
class point
{
public:
	ld x, y;
	point(){ x = y = 0.0; }
	point(ld xx, ld yy) :x(xx), y(yy){}
	ld dist(point p1, point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y-p2.y)*(p1.y-p2.y)); }
	bool operator<(point p)const{ if (fabs(x - p.x)>EPS)return x < p.x; return y < p.y; }
};
class line
{
public://ax+by+c
	ld a, b, c;
	line(){ a = b = c = 0.0; }
	line(ld aa, ld bb, ld cc) :a(aa), b(bb), c(cc){};
	line pointsToLine(point p1, point p2)
	{
		line l;
		if (fabs(p1.x - p2.x) < EPS){ l.a = 1.0; l.b = 0.0; l.c = -p1.x; }
		else
		{l.a = -(ld)(p1.y - p2.y) / (p1.x - p2.x); l.b = 1.0;l.c = -(ld)(l.a * p1.x) - p1.y;}
		return l;
	}
	bool areParallel(line l1, line l2) { return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS); }
	bool areIntersect(line l1, line l2, point &p) {
		if (areParallel(l1, l2)) return false;
		p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
		if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c); else p.y = -(l2.a * p.x + l2.c); return true;
	}
};
point p[MAX];
int main()
{
	int t, n; sc(t);
	while (t--)
	{
		sc(n);
		lop(i, 0, n)cin >> p[i].x >> p[i].y;
		sort(p, p + n);
		int max_height = 0; ld ans = 0;
		for (int i = n-1; i > 0; i--)
		{
			if (!(p[i].y < p[i - 1].y))continue;
			if (p[i - 1].y <= max_height)continue;
			line tmp(0, 1, -max_height);
			line l; l = l.pointsToLine(p[i-1], p[i]);
			point c; l.areIntersect(l, tmp, c);
			ans += p[i - 1].dist(p[i - 1], c);
			max_height = p[i - 1].y;
		}
		pr3(ans);
	}
}