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
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
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
int const MAX = 1000 + 7;
int const MOD = 1e9 + 7;
int dp1[MAX][MAX], dp2[MAX][MAX], dp3[MAX][MAX], dp4[MAX][MAX], grid[MAX][MAX];;
int n, m;
int main()
{
    cin >> n >> m;
    lop(i, 1, n + 1)lop(j, 1, m + 1)cin >> grid[i][j];

    lop(i, 1, n + 1)lop(j, 1, m + 1)
        dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + grid[i][j];
    loop(i, n + 1, 1)loop(j, m + 1, 1)
        dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + grid[i][j];
    loop(i, n + 1, 1)lop(j, 1, m + 1)
        dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + grid[i][j];
    lop(i, 1, n + 1)loop(j, m + 1, 1)
        dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + grid[i][j];

    int ans = 0;
    lop(i, 1, n + 1)lop(j, 1, m + 1) {
        if (i==1||i==n||j==1||j==m)continue;
        ans = max(ans, max(dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j],
            dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]));
    }
    cout << ans << endl;
}