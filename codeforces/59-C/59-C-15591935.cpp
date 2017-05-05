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
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int n, m, k;
int arr[26];
vii pos;
int main() 
{	
	int k; string s;
	cin >> k >> s;
	int n = s.length();
	lop(i, 0, (n / 2)+n%2)
	{
		if (s[i] != s[n - i - 1])
		{
			if (s[i] == '?') {
				s[i] = s[n - i - 1]; arr[s[i] - 'a'] = 1; continue;
			}
			if (s[n-i-1] == '?') {
				s[n - i - 1] = s[i]; arr[s[i] - 'a'] = 1; continue;
			}
			return(cout << "IMPOSSIBLE\n", 0);
		}
		if (s[i] != '?'){
			arr[s[i] - 'a'] = 1; continue;
		}
		pos.push_back(ii(i, n - i - 1));
	}
	int m = 0;
	lop(i, 0, k)m += arr[i];
	loop(i, sz(pos), 0)
	{
		char x = 'a';
		loop(j, k, 0)if (arr[j] == 0) { x = 'a' + j; arr[j] = 1; m++; break; }
		s[pos[i].first] = s[pos[i].second] = x;
	}
	if(k!=m)
		return(cout << "IMPOSSIBLE\n", 0);
	cout << s << endl;
}