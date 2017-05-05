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
class point
{
public: 
    ld x, y;
	point(){ x = y = 0.0; }
	point(ld xx, ld yy) :x(xx), y(yy){}
    static ld dist(point p1, point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
	 static point rotate_point(point pp, ld angle, point around){
	angle = (angle*PI) / 180.000;
	return point(cos(angle) * (pp.x - around.x) - sin(angle) * (pp.y - around.y) + around.x,
		sin(angle) * (pp.x - around.x) + cos(angle) * (pp.y - around.y) + around.y);}
	bool operator==(point p)const{ return fabs(x - p.x) < EPS&&fabs(y - p.y) < EPS; }
};
struct vec
{
	ld x, y;
	vec(ld _x, ld _y) : x(_x), y(_y) {}
	static vec toVec(point a, point b){return vec(b.x - a.x, b.y - a.y);};
	static ld dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
	static ld norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
	static ld angle(point a, point o, point b)
	{
		vec oa = toVec(o, a), ob = toVec(o, b);
		return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
	}
	static ld cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
	static bool ccw(point p, point q, point r) { return cross(toVec(p, q), toVec(p, r)) > 0; }
};
class polygon
{
public:
	static ld area(const vector<point> &P) 
	{ 
		ld result = 0.0, x1, y1, x2, y2;
		lop(i,0,sz(P)-1)
		{ 
			x1 = P[i].x; x2 = P[i+1].x; 
			y1 = P[i].y; y2 = P[i+1].y; 
			result += (x1 * y2 - x2 * y1); 
		} 
		return fabs(result) / 2.0;
	}
	static bool inPolygon(point pt, const vector<point> &P)
	{ 
		if (sz(P) == 0)return false;
		ld sum = 0; 
		lop(i,0,sz(P)-1)
		{
			if (vec::ccw(pt, P[i], P[i+1])) sum += vec::angle(P[i], pt, P[i+1]); 
			else sum -= vec::angle(P[i], pt, P[i+1]);
		} 
		return fabs(fabs(sum) - 2*PI) < EPS;
	}
	static point lineIntersectSeg(point p, point q, point A, point B)
	{ 
		ld a = B.y - A.y; 
		ld b = A.x - B.x; 
		ld c = B.x * A.y - A.x * B.y; 
		ld u = fabs(a * p.x + b * p.y + c); 
		ld v = fabs(a * q.x + b * q.y + c);
		return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); 
	}
	static vector<point> cutPolygon(point a, point b, const vector<point> &Q) 
	{ 
		vector<point> P; 
		lop(i,0,sz(Q)-1)
		{
			ld left1 = vec::cross(vec::toVec(a, b), vec::toVec(a, Q[i])), left2 = 0; 
			if (i != sz(Q)-1) left2 = vec::cross(vec::toVec(a, b), vec::toVec(a, Q[i+1])); 
			if (left1 > -EPS) P.push_back(Q[i]);
			if (left1 * left2 < -EPS) 
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
		} 
		if (!P.empty() && !(P.back() == P.front())) P.push_back(P.front());
		return P; 
	}
};
int main()
{
	int n,w,h,x,y,t=0;
	while(cin>>n>>w>>h>>x>>y)
	{
		vector<point>p;
		p.push_back(point(0,0)),p.push_back(point(w,0)),
		p.push_back(point(w,h)),p.push_back(point(0,h)),
		p.push_back(point(0,0));
		lop(i,0,n)
		{
			int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
			vector<point>cuts =polygon::cutPolygon(point(x1,y1),point(x2,y2),p);
			if(polygon::inPolygon(point(x,y),cuts))p=cuts;else p= polygon::cutPolygon(point(x2,y2),point(x1,y1),p);
		}
		cout<<"Case #"<<++t<<": ";
		pr3(polygon::area(p));
	}
}