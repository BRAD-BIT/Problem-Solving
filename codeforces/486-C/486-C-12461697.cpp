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
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 5 * 1e5 + 7; ii a[MAX]; int n, p; string s; int ans = 0; int cur; ii po[MAX];
void left()
{
    cur = p - 1;
    while (a[cur].first != -1)
    {
        if (a[cur].first + 1 < n / 2 && p>n / 2)break;
        ans += cur - a[cur].first;
        cur = a[cur].first;
        int x = abs(max(s[cur], s[n - 1 - cur]) - min(s[cur], s[n - 1 - cur]));
        int y = (min(s[cur], s[n - 1 - cur]) - 'a') + ('z' - max(s[cur], s[n - 1 - cur])) + 1;
        ans += min(x, y);
        if (a[cur].first == cur)break;
    }
}
void right()
{
    cur = p - 1;
    while (a[cur].second != -1)
    {
        if (a[cur].second + 1 > n / 2&&p<n/2)break;
        ans += a[cur].second - cur;
        cur = a[cur].second;
        int x = abs(max(s[cur], s[n - 1 - cur]) - min(s[cur], s[n - 1 - cur]));
        int y = (min(s[cur], s[n - 1 - cur]) - 'a') + ('z' - max(s[cur], s[n - 1 - cur])) + 1;
        ans += min(x, y);
        if (a[cur].second == cur)break;
    }
}
int main()
{
     cin >> n >> p >> s; 
     int o = -1; int u = -1;
     o = -1; u = -1; lop(i, 0, n / 2){ a[i].first = o; if (s[i] != s[n - 1 - i])o = i; if (s[i] != s[n - 1 - i] && u == -1)u = i; po[i].first = u; }
     o = -1; u = -1; loop(i, n / 2, 0){ a[i].second = o; if (s[i] != s[n - 1 - i])o = i; if (s[i] != s[n - 1 - i] && u == -1)u = i; po[i].second = u; }
     o = -1; u = -1; lop(i, n / 2, n){ a[i].first = o; if (s[i] != s[n - 1 - i])o = i;  if (s[i] != s[n - 1 - i] && u == -1)u = i; po[i].first = u; }
     o = -1; u = -1; loop(i, n, n / 2){ a[i].second = o; if (s[i] != s[n - 1 - i])o = i;  if (s[i] != s[n - 1 - i] && u == -1)u = i; po[i].second = u; }
    if (n % 2 != 0 && p == (n / 2) + 1)
    {
        if (a[p - 1].first == -1)return(cout << "0\n", 0);
        p--, ans++;
    }
    int x = abs(max(s[p-1], s[n - 1 - p+1]) - min(s[p-1], s[n - 1 - p+1]));
    int y = (min(s[p-1], s[n - 1 - p+1]) - 'a') + ('z' - max(s[p-1], s[n - 1 - p+1])) + 1;
    ans = min(x, y);
    if (a[p - 1].first == -1 && a[p - 1].second == -1)return(cout << ans << endl , 0);
    if (a[p - 1].first == -1)right();
    else 
    if (a[p - 1].second == -1)left();
    else
    if (abs(po[p - 1].first - (p - 1))<abs(po[p - 1].second - (p - 1)))
    {
        left(); ans += p - cur - 1; right();
    }
    else
    {
        right();
        ans += cur + 1-p;
        left();
    }
    cout << ans << endl;
}