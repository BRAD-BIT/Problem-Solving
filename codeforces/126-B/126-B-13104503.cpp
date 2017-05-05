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
vi P; string s;
void Fail_Fun()
{
    int n = s.length();
    P.resize(n, 0);
    for (int i = 1,k = 0; i < n; i++)
    {
        while (k>0 && s[i] != s[k])k = P[k - 1];
        if (s[i] == s[k])P[i] = ++k; else P[i] = k;
    }
    bool found = 0; lop(i, 0, n - 1)if (P[i] == P[n - 1]){ found = 1; break; }
    if (P[n - 1] == 0)cout << "Just a legend\n";
    else
    if (P[n - 1] != 0&&found)cout << s.substr(0, P[n - 1]) << endl;
    else
    if (P[P[n - 1]-1] != 0){ cout << s.substr(0, P[P[n - 1]-1]) << endl; return; }  
    else
    cout << "Just a legend\n";
}
int main()
{
    cin >> s;
    Fail_Fun();
}