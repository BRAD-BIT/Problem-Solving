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

#define lop(i,n)   for(ll i=0;i<n;++i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define ld         long double
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define clr(a,b)   memset(a,b,sizeof a)
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
ll mod = 1e9 + 7;
const int MAX = 100 + 7;
struct ass{ ll a, b, c, d; };
char arr[111][11111]; ass ne[111][11111]; int mn[111][11111]; int m;
ll len(int indx,int a)
{
    if (a == -1)return oo;
    int x; if (a > indx)x = a - indx; else x = indx - a;
    return min(abs(a + m - indx), min(abs(m - a + indx),x));
}
int main()
{
    int n; cin >> n >> m;
    lop(i, n)
    {
        int a = -1, b = -1, c = -1, d = -1;
        lop(j, m){ cin >> arr[i][j]; if (arr[i][j]=='1'){ b = j; if (a == -1)a = j; } }
        lop(j, m){ if (arr[i][j] == '1')c = j; ne[i][j].a = a; ne[i][j].b = b; ne[i][j].c = c; }
        for (int j = m - 1; j >= 0; j--){ if (arr[i][j] == '1')d = j; ne[i][j].d = d; }
        lop(j, m)
        {
            vll ans; 
            ans.push_back(len(j, ne[i][j].a));
            ans.push_back(len(j, ne[i][j].b));
            ans.push_back(len(j, ne[i][j].c));
            ans.push_back(len(j, ne[i][j].d));
            sort(all(ans));
            mn[i][j] = ans[0];
        }
    }
    ll ans = oo;
    lop(i, m)
    {
        ll sum = 0;
        lop(j, n)sum += (mn[j][i]>0)*mn[j][i];
        ans = min(ans, sum);
    }
    if (ans != oo)cout << ans << endl; else cout << -1 << endl;
}