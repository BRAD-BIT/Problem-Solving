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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
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
	point(ld xx, ld yy) :x(xx), y(yy){}
	static ld dis(point p1, point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
	static point rotate_point(point pp, ld angle, point around){
		angle = (angle*PI) / 180.000;
		return point(cos(angle) * (pp.x - around.x) - sin(angle) * (pp.y - around.y) + around.x,
			sin(angle) * (pp.x - around.x) + cos(angle) * (pp.y - around.y) + around.y);
	}
};
pair<point, ld> circumcircle(point a, point b, point c){
	ld A = 2 * (b.x - a.x);
	ld B = 2 * (b.y - a.y);
	ld C = (a.x)*(a.x) + (a.y)*(a.y) - (b.x)*(b.x) - (b.y)*(b.y);
	ld D = 2 * (c.x - a.x);
	ld E = 2 * (c.y - a.y);
	ld F = (a.x)*(a.x) + (a.y)*(a.y) - (c.x)*(c.x) - (c.y)*(c.y);
	ld x = (B*F - C*E) / (A*E - B*D);
	ld y = (C*D - A*F) / (A*E - B*D);
	return pair<point, ld>(point(x, y), sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y)));
}
int main()
{
	int n, t = 1;
	while (1)
	{
		sc(n); if (n == 0)return 0;
		point p[3];
		ld maxX=-oo, maxY=-oo, minX=oo, minY=oo;
		lop(i, 0, 3)cin >> p[i].x >> p[i].y;
		pair<point, ld>c = circumcircle(p[0], p[1], p[2]);
		ld theta = 360.000 / n;
		lop(i, 0, n)
		{
			p[0]=point::rotate_point(p[0], theta,c.first);
			maxX = max(maxX, p[0].x);
			maxY = max(maxY, p[0].y);
			minX = min(minX, p[0].x);
			minY = min(minY, p[0].y);
		}
		cout << "Polygon " << t++ << ": ";
		pr3((maxX - minX)*(maxY - minY));
	}
}