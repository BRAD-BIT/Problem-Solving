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
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int ans = s1.length() + s2.length();
		lop(i, 0, s2.length())
		{
			bool test = 1;
			int len = max(max(int(s2.length()), int(s1.length())), max(int(s2.length()),int(i+s1.length())));
			for (int j = 0, k = i; j < s1.length() && k < s2.length(); ++k, j++)if ((s1[j] == '2'&&s2[k] == '2')){ test = 0; break; }
			if (test)ans = min(ans, len);
		}
		swap(s1, s2);
		lop(i, 0, s2.length())
		{
			bool test = 1;
			int len = max(max(int(s2.length()), int(s1.length())), max(int(s2.length()), int(i + s1.length())));
			for (int j = 0, k = i; j < s1.length() && k < s2.length(); ++k, j++)if ((s1[j] == '2'&&s2[k] == '2')){ test = 0; break; }
			if (test)ans = min(ans, len);
		}
		cout << ans << endl;
	}
}