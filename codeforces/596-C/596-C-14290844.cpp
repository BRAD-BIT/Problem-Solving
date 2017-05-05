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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
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
int const MAX = 1e5 + 7;
int w[MAX]; ii p[MAX], ans[MAX];
bool comp(ii a, ii b)
{

    if ((a.second - a.first) != (b.second - b.first))return (a.second - a.first) < (b.second - b.first);
    if (a.first != b.first)return a.first < b.first;
    return a.second < b.second;
}
map<ll, ll>mp1, mp2, mp3;
int main()
{
    int n, num = 0; cin >> n;
    lop(i, 0, n) { cin >> p[i].first >> p[i].second; mp1[p[i].second - p[i].first]++; }
    lop(i, 0, n)cin >> w[i];
    sort(p, p + n, comp);
    lop(i, 0, n)if (mp3.count(p[i].second - p[i].first) == 0)mp3[p[i].second - p[i].first] = i;
    lop(i, 0, n)
    {
        if (mp2[w[i]] == mp1[w[i]])return(cout << "NO\n", 0);
        ans[i] = p[mp3[w[i]] + mp2[w[i]]++];
        if (!i)continue;
        if(!(ans[i].first>ans[i-1].first||ans[i].second>ans[i-1].second))
            return(cout << "NO\n", 0);
    }
    cout << "YES\n";
    lop(i, 0, n)cout << ans[i].first << " " << ans[i].second << endl;
}