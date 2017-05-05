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
const int MAX = 4 * 1e5 + 7;
map<int, int>mp1, mp2, mp3;
void add(int n)
{
    set<int>se;
    if (mp2[n]){ cout << "Already on\n"; return; }
    for (int i = 1; i*i <= n; ++i)
    {
        int a = i, b = n / i;
        if (n%a == 0 && a != 1){ se.insert(a); if (mp1[a]){ cout << "Conflict with " << mp1[a] << endl; return; } }
        if (n%b == 0 && b != 1){ se.insert(b); if (mp1[b]){ cout << "Conflict with " << mp1[b] << endl; return; } }
    }
    cout << "Success\n";
    mp2[n]=1;
    for (set<int>::iterator it = se.begin(); it != se.end(); it++)mp1[*it]=n;
}
void remove(int n)
{
    set<int>se;
    if (!mp2[n]){ cout << "Already off\n"; return; }
    mp2[n] = 0;
    for (int i = 1; i*i <= n; ++i)
    {
        int a = i, b = n / i;
        if (n%a == 0 && a != 1)mp1[a]=0;
        if (n%b == 0 && b != 1)mp1[b]=0;
    }
    cout << "Success\n";
}
int main()
{
    int n, m; cin >> n >> m;
    lop(i,0,m)
    {
        char c; int num; cin >> c >> num;
        if (c == '+')add(num);
        if (c == '-')remove(num);
    }
}