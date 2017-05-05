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
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
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
#define pr4(n)     printf("%lld\n",n)
#define pr3(n)     cout<<fixed<<setprecision(4)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 100 + 7;
const int MOD = 1e9 + 7;
struct node {
	ld r, s, p;node(ld _r=0,ld _s=0,ld _p=0):r(_r),s(_s),p(_p){}
	void operator+=(node &n){
		r += n.r; s += n.s; p += n.p;}
	node operator*(ld x) {
		return node(r*x, s*x, p*x);
	}
};
map<pair<ii,int>, node>mem;
node solve(int r, int s, int p)
{
	if (r == 0 && s == 0)return node(0, 0, 1);
	if (r == 0 && p == 0)return node(0, 1, 0);
	if (p == 0 && s == 0)return node(1, 0, 0);
	if (mem.count(make_pair(make_pair(r, s), p)) != 0)
		return mem[make_pair(make_pair(r, s), p)];
	node ans;
	ld t = r*s + r*p + s*p;
	if (r&&s)ans+=(solve(r, s - 1, p)*((r*s)/t));
	if (r&&p)ans+=(solve(r - 1, s, p)*((r*p)/t));
	if (s&&p)ans+=(solve(r, s, p - 1)*((s*p)/t));

	return  mem[make_pair(make_pair(r, s), p)] = ans;
}
int main()
{
	int r, s, p;
	sc(r), sc(s), sc(p);
	node ans = solve(r, s, p);
	ld all = ans.p + ans.r + ans.s;
	cout << fixed << setprecision(12) << ans.r / all << " " << ans.s / all << " " << ans.p / all << endl;
}