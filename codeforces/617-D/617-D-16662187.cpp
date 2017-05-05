#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
#define lop(i,a,n) for(ll i=a;i<n;++i)
#define loop(i,n,a)for(ll i=n-1;i>=a;--i)
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
#define pr3(n)     cout<<fixed<<setprecision(2)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS pow(10,-9)
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 2000 + 7;
const int MOD = 1e9 + 7;
ii p[3];
bool test(int i, int j, int k)
{
	bool t1 = (p[i].first == p[k].first || p[j].first == p[k].first) && (p[k].second >= min(p[i].second, p[j].second)&&p[k].second <= max(p[i].second, p[j].second));
	bool t2 = (p[i].second == p[k].second || p[j].second == p[k].second) && (p[k].first >= min(p[i].first, p[j].first)&&p[k].first <= max(p[i].first, p[j].first));
	return t1 || t2;
}
int main()
{
	lop(i, 0, 3)cin >> p[i].first >> p[i].second;
	if ((p[0].first == p[1].first&&p[1].first == p[2].first) || (p[0].second == p[1].second && p[1].second == p[2].second))
		return(cout << "1\n", 0);
	if(test(0,1,2)|| test(0, 2, 1) || test(1, 2, 0) )
		return(cout << "2\n", 0);
	cout << "3\n";
}