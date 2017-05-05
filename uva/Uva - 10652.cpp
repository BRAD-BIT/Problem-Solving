#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
#define EPS 1e-9
#define PI 2*acos(0.0)
class point
{
public:
    long double x, y;
	point(){ x = y = 0.0; }
	point(long double xx, long double yy) :x(xx), y(yy){}
    static long double dist(point p1, point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
	 static point rotate_point(point pp, long double angle, point around){
	angle = (angle*PI) / 180.000;
	return point(cos(angle) * (pp.x - around.x) - sin(angle) * (pp.y - around.y) + around.x,
		sin(angle) * (pp.x - around.x) + cos(angle) * (pp.y - around.y) + around.y);}
	bool operator==(point p)const{ return fabs(x - p.x) < EPS&&fabs(y - p.y) < EPS; }
};
struct vec
{
	long double x, y;
	vec(long double _x, long double _y) : x(_x), y(_y) {}
	static vec toVec(point a, point b){return vec(b.x - a.x, b.y - a.y);};
	static long double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
	static bool ccw(point p, point q, point r) { return cross(toVec(p, q), toVec(p, r)) > 0; }
	static bool collinear(point p, point q, point r) { return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
};
point pivot;
class polygon
{
public:
	static long double area(const vector<point> &P)
	{
		long double result = 0.0, x1, y1, x2, y2;
		for(int i=0;i<(int)P.size()-1;++i)
		{
			x1 = P[i].x; x2 = P[i+1].x;
			y1 = P[i].y; y2 = P[i+1].y;
			result += (x1 * y2 - x2 * y1);
		}
		return fabs(result) / 2.0;
	}
	static bool angleCmp(point a, point b)
	{
		if (vec::collinear(pivot, a, b))
		return point::dist(pivot, a) < point::dist(pivot, b);
		long double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
		long double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
		return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
	}
	static vector<point> Convex_Hull(vector<point> P)
	{
		int n=P.size();
		if (n <= 3)
		{
			if (!(P[0] == P[n-1])) P.push_back(P[0]);
			return P;
		}
		int P0 = 0;
		for(int i=1;i<n;++i)
			if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
		swap(P[0],P[P0]);pivot = P[0];
        sort(++P.begin(), P.end(), angleCmp);
		vector<point> S;
		S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
		int i=2,j;
		while (i < n)
		{
			j = S.size()-1;
			if (vec::ccw(S[j-1], S[j], P[i])||
					vec::collinear(S[j-1], S[j], P[i])) S.push_back(P[i++]);
			else S.pop_back();
		}
		return S;
	}
};
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//freopen("ot.txt", "wt", stdout);
#endif
	int t,n;long double theta,x,y,w,h;cin>>t;
	while(t--)
	{
		cin>>n;vector<point>P;
		long double ans1,ans2=0;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>w>>h>>theta;
			point c[4];
			c[0]=point(x-(w/2),y-(h/2))
				,c[1]=point(x-(w/2),y+(h/2))
				,c[2]=point(x+(w/2),y+(h/2))
				,c[3]=point(x+(w/2),y-(h/2));
			for(int j=0;j<4;j++)P.push_back(point::rotate_point(c[j],-1*theta,point(x,y)));
			ans2+=w*h;
		}
		P=polygon::Convex_Hull(P);
		ans1=polygon::area(P);
		long double ans=(ans2/ans1)*100.00;
		cout<<fixed<<setprecision(1)<<(ans)<<" %\n";
	}
}
