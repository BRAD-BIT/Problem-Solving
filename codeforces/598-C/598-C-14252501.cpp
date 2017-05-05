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
#define R_W        R_("easy.in"),W_("easy.out")
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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
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
const int MAX = 100000 + 7;
class point
{
public:
    ld x, y;
    point() { x = y = 0.0; }
    point(ld xx, ld yy) :x(xx), y(yy) {}
};
struct vec
{
    ld x, y;
    vec(ld _x, ld _y) : x(_x), y(_y) {}
    static vec toVec(point a, point b)
    {
        return vec(b.x - a.x, b.y - a.y);
    };
    static ld dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
    static ld norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
    static ld angle(point a, point o, point b)
    {
        vec oa = toVec(o, a), ob = toVec(o, b);
        return (acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))))*(180.000/(ld)(2.00*acos(0.0)));
    }
};
point p[MAX];
pair<ld, int>ans[MAX];
bool comp(pair<ld, int>a, pair<ld, int>b)
{
    return a.first < b.first;
}
int main()
{
    int n; cin >> n; 
    lop(i, 0, n)cin >> p[i].x >> p[i].y;
    lop(i, 0, n)
    {
        if (p[i].x > 0 && p[i].y >= 0)
            ans[i] = make_pair(vec::angle(p[i], point(0, 0), point(1, 0)), i);
        else
        if (p[i].x <= 0 && p[i].y > 0)
            ans[i] = make_pair(90+vec::angle(p[i], point(0, 0), point(0, 1)), i);
        else
        if (p[i].x < 0 && p[i].y <= 0)
            ans[i] = make_pair(180+vec::angle(p[i], point(0, 0), point(-1, 0)), i);
        else
        if (p[i].x >= 0 && p[i].y < 0)
            ans[i] = make_pair(270+vec::angle(p[i], point(0, 0), point(0, -1)), i);
    }
    sort(ans, ans + n, comp);
    pair<ld, ii>out; out.first = oo;
    lop(i, 0, n - 1)
    {
        if (ans[i + 1].first - ans[i].first < out.first)
            out = pair<ld, ii>(ans[i + 1].first - ans[i].first, ii(ans[i].second+1, ans[i+1].second+1));
    }
    if(360-ans[n-1].first+ans[0].first<out.first||ans[n - 1].first + ans[0].first<out.first)
        out = pair<ld, ii>(360-ans[n-1].first+ans[0].first<out.first, ii(ans[0].second + 1, ans[n-1].second + 1));
    cout << out.second.first << " " << out.second.second << endl;
}