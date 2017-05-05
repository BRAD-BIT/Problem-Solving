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
class point
{
public:
	int x, y;
	point(){ x = y = 0; }
	point(int xx, int yy) :x(xx), y(yy){}
};
void intersection_rectangle(point r1[2], point r2[2])
{
	int a = max(r1[0].x, r2[0].x);
	int b = max(r1[0].y, r2[0].y);
	int c = min(r1[1].x, r2[1].x);
	int d = min(r1[1].y, r2[1].y);
	if (a >= c || b >= d)cout << "No Overlap\n";
	else cout << a << " " << b << " " << c << " " << d << endl;
}
int main()
{
	int n; cin >> n;
	while (n--)
	{
		point r1[2], r2[2];
		cin >> r1[0].x >> r1[0].y >> r1[1].x >> r1[1].y;
		cin >> r2[0].x >> r2[0].y >> r2[1].x >> r2[1].y;
		intersection_rectangle(r1, r2);
		if (n)cout << endl;
	}
}