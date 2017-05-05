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
#define lop(i,a,n)   for(int i=a;i<n;++i)
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
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 4 * 1e5 + 7;

bool comp(pair<ii, ii> a, pair<ii, ii> b){ return a.first.first < b.first.first; }
bool comp2(pair<ii, ii> a, pair<ii, ii> b){ return a.first.second < b.first.second; }
pair<ii, ii>ans[MAX];
int main()
{
    int n; cin >> n;
    lop(i, 0, n){ cin >> ans[i].first.first; ans[i].first.second = i; ans[i].second.first = oo; ans[i].second.second = 0; }
    sort(ans, ans + n, comp);
    lop(i,0, n)
    {
        if (i == 0)ans[i].second.first = abs(ans[i].first.first - ans[i + 1].first.first);
        else
        if (i == n - 1)ans[i].second.first = abs(ans[i].first.first - ans[i - 1].first.first);
        else
        ans[i].second.first = min(abs(ans[i].first.first - ans[i - 1].first.first), abs(ans[i].first.first - ans[i + 1].first.first));
        ans[i].second.second = max(abs(ans[i].first.first - ans[0].first.first), abs(ans[i].first.first - ans[n - 1].first.first));
    }
    sort(ans, ans + n, comp2);
    lop(i, 0, n)cout << ans[i].second.first << " " << ans[i].second.second << endl;
}