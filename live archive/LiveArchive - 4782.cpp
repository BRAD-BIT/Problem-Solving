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
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#include<string>
#include<cstdio>
using namespace std;
#define iter(it,S) for(set<int>::iterator it = S.begin(); it != S.end(); ++it)
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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1000 + 7;
int const MOD = 9999991;
pair<string, pair<ld,ld> >r[MAX];
bool comp(pair<string, pair<ld, ld> >a, pair<string, pair<ld, ld> >b)
{
	if(a.second.first!=b.second.first)return a.second.first < b.second.first;
	return a.second.second < b.second.second;
}
int main()
{

    //R_("input.txt");
	string in; ll n; getline(cin, in); n = stoll(in);
	lop(i, 0, n)
	{
		getline(cin, r[i].first);
		getline(cin, in);
		ld a=-1, b, c, d; string s;
		lop(j, 0, in.length())
		{
			if (in[j] !='.')s += in[j];
			else
			{
				if (a == -1){ a = stold(s); b = in[j + 1] - '0'; j += 2; s.clear(); }
				else{ c = stold(s); d = in[j + 1] - '0';  }
			}
		}
		r[i].second.first = a + b / 10;
		r[i].second.second = c + d / 10;
		if (r[i].first[r[i].first.length() - 1] == ' ')r[i].first.erase(r[i].first.length() - 1, 1);
	}
	sort(r, r + n, comp);
	int q; cin >> q;
	lop(i, 0, q)
	{
		vs ans; int y; cin >> y;
		lop(j, 0, n)if (int(r[j].second.first) <= y && int(r[j].second.second) >= y)ans.push_back(r[j].first);
		cout << "Galactic year " << y << ": ";
		lop(j, 0, sz(ans)){ if (j)cout << ", "; cout << ans[j]; }
		if (sz(ans) == 0)cout << "None";
		cout << endl;
		ans.clear();
	}
}