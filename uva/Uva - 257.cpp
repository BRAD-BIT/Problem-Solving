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
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
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
const int MAX = 3*1e2 + 7;
const int MOD = 1073741824;
bool is_pal[MAX][MAX];
bool is_palinword(string s)
{
	memset(is_pal, 0, sizeof is_pal);
	set<string> vv;
	lop(i, 0, s.length())is_pal[i][i] = 1;
	lop(len, 2, min(5,int(s.length()+1)))
	{
		lop(i, 0, s.length()-len+1)
		{
			int j = i + len - 1;
			if (len == 2)is_pal[i][j] = (s[i] == s[j]);
			else is_pal[i][j] = is_pal[i + 1][j - 1] && (s[i] == s[j]);
			if (len > 2 && is_pal[i][j])vv.insert(s.substr(i, len));
		}
	}
	vs xx;
	for (auto i : vv)xx.push_back(i);
	lop(i, 0, sz(xx))lop(j, i + 1, sz(xx)) {
		if (xx[i].length() == xx[j].length())return true;
		if (xx[i].find(xx[j]) == string::npos && xx[j].find(xx[i]) == string::npos)
			return true;
	}
		
	
	return false;
}
int main()
{
	string s;
	while (cin>>s)
	{
		string tmp;
		if (is_palinword(s))cout << s << endl;
	}
}