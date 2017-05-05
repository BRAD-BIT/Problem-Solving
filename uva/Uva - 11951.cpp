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
const int MAX = 1e2 + 7;
const int MOD = 1073741824;
int p[MAX][MAX], sum[MAX][MAX];
int main()
{
	int T; cin >> T;
	lop(t, 1, T + 1) {
		int n, m, K; cin >> n >> m >> K;
		lop(i, 0, n)lop(j, 0, m)cin >> p[i][j];
		lop(i, 0, n)sum[i][m - 1] = p[i][m - 1];
		lop(i, 0, n)loop(j, m - 1, 0)sum[i][j] = p[i][j] + sum[i][j + 1];
		lop(j, 0, m)loop(i, n - 1, 0)sum[i][j] += sum[i + 1][j];

		ii ans(0, 0);
		lop(i, 0, n)lop(j, 0, m)lop(k, i, n)lop(w, j, m)
		{
			int s = sum[i][j];
			if (k + 1 < n)s -= sum[k + 1][j];
			if (w + 1 < m)s -= sum[i][w + 1];
			if (k + 1 < n&&w + 1 < m)s += sum[k + 1][w + 1];
			int num = (k - i + 1)*(w - j + 1);
			if (s <= K&&ans.first < num || s <= K&&ans.first == num&&ans.second>s)ans = ii(num, s);
		}
		printf("Case #%d: %lld %lld\n", t, ans.first, ans.second);
	}
}