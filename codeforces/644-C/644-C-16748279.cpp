//In the name of Allah
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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
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
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
pair<string, string>http[MAX];
map<string, int>mp;
map<vs, vs>ans;
bool comp(pair<string, string>a, pair<string, string>b)
{
	if (a.first != b.first)return a.first < b.first;
	return a.second < b.second;
}
int main()
{	
	int n, m = 0, i = 0; cin >> n;
	while(n--)
	{
		string s; cin >> s;
		if (mp[s])continue;
		int last_sl = s.substr(7, s.length()).find_first_of('/') + 7;
		//cout << last_sl << endl;
		//continue;
		if (last_sl == 6)http[i] = pair<string,string>(s, "");
		else
		{
			http[i] = pair<string, string>(s.substr(0,last_sl),s.substr(last_sl,s.length()));
		}
		//cout << http[i].first << " === " << http[i].second << endl;
		i++; mp[s]++; m++;
	}

	//return 0;
	sort(http, http + m, comp);
	string temp = http[0].first;
	vs q; http[m] = pair<string, string>("fuck", "you");
	lop(i, 0, m + 1)
	{
		if (temp == http[i].first)
		{
			q.push_back(http[i].second);
		}
		else
		{
			ans[q].push_back(temp);
			temp = http[i].first;
			q.clear();
			q.push_back(http[i].second);
		}
	}
	int x = 0;
	for (map<vs, vs>::iterator it = ans.begin(); it != ans.end(); it++)
		if (sz(it->second) > 1)x++;
	cout << x << endl;
	for (map<vs, vs>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		if (sz(it->second) <= 1)continue;
		lop(i, 0, sz(it->second))cout << it->second[i] << " ";
		cout << endl;
	}
}