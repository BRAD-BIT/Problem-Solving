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
class point
{
public:
	ld x, y;
	point(){ x = y = 0.0; }
	point(ld xx, ld yy) :x(xx), y(yy){}
	static ld dis(point p1, point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
};
struct vec
{
	ld x, y;
	vec(ld _x, ld _y) : x(_x), y(_y) {}
	static vec toVec(point a, point b){return vec(b.x - a.x, b.y - a.y);};
	static vec scale(vec v, ld s) {return vec(v.x * s, v.y * s);}
	static point translate(point p, vec v) {return point(p.x + v.x, p.y + v.y);}
	static ld dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
	static ld norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
	static ld distToLineS(point p, point a, point b, point &c)
	{ 
		vec ap = toVec(a, p), ab = toVec(a, b);
		ld u = dot(ap, ab) / norm_sq(ab); c = translate(a, scale(ab, u));
		if (u < 0.0) { c = point(a.x, a.y); } 
		if (u > 1.0) { c = point(b.x, b.y); } 
		return p.dis(p, c);
	}
};
point p[MAX];
int main()
{
	point M; int n;
	while (cin>>M.x>>M.y)
	{
		sc(n);
		lop(i, 0, n + 1)cin >> p[i].x >> p[i].y;
		point ans, c; ld m = oo, re;
		lop(i, 0, n)
		{
			re = vec::distToLineS(M, p[i], p[i + 1], c);
			if (re < m){ m = re; ans = c; }
		}
		pr3(ans.x); pr3(ans.y);
	}
}