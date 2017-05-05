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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n
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
bool circle2PtsRad(point p1, point p2, ld r, point &c)
{
	ld d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	ld det = r * r / d2 - 0.25; 
	if (det < 0.0) return false;
	ld h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h; 
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h; 
	return true;
}
point p[200];
int main()
{
	int n; ld r; 
	while (1)
	{
		sc(n); if (n == 0)return 0;
		lop(i, 0, n)cin >> p[i].x >> p[i].y;
		cin >> r;
		lop(i, 0, n)
		lop(j, 0, n)
		{
			if (i == j)continue;
			point c; 
			bool test = 0;
			if (circle2PtsRad(p[i], p[j], r, c))
			{
				test = 1;
				lop(k, 0, n)
				{
					if (point::dis(c,p[k])>r+EPS){ test = 0; break; }
				}
			}
			if (test){ cout << "The polygon can be packed in the circle.\n"; goto N; }
		}
		cout << "There is no way of packing that polygon.\n";
	N:;
	}
}