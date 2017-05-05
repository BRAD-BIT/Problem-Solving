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
struct edge { int first, second, third; };
bool comp1(edge a, edge b) { if (a.first != b.first)return a.first < b.first; return a.second>b.second; }
bool comp2(edge a, edge b) { return a.third < b.third; }
edge e[MAX];
int main() 
{
    int n, m; cin >> n >> m;
    lop(i, 0, m) { cin >> e[i].first >> e[i].second; e[i].third = i; }
    sort(e, e + m, comp1);
    int x = 2, y = 3, z = 2, w = 0, o = 1;
    lop(i, 0, m)
    {
        if (e[i].second)
        {
            e[i].first = 1, e[i].second = z++;
        }
        else
        {
            if (y < z) {
                e[i].first = x, e[i].second = y;
                if (w + 1 == o)y++, x = 2, w = 0, o++;
                else x++, w++;
            }
            else return(cout << "-1\n", 0);
        }
    }
    sort(e, e + m, comp2);
    lop(i, 0, m)cout << e[i].first << " " << e[i].second << endl;
}