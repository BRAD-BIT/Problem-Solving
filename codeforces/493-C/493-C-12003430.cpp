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
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
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
#define pr2(n)     printf("%d " ,n)
#define pr1(n)     printf("%d\n",n)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 2 * 1e5;
vii a;
int main()
{
    int n; cin >> n; for (int i = 0; i < n; i++){ int c; cin >> c; a.push_back(make_pair(c,1)); }
    int m; cin >> m; for (int i = 0; i < m; i++){ int c; cin >> c; a.push_back(make_pair(c, 2)); }
    sort(all(a));
    int sum1 = n * 3; int sum2 = m * 3; int num = a[0].first; 
    int M = sum1 - sum2; ii ans = make_pair(sum1, sum2); a.push_back(make_pair(-5451212, 1));
    for (int i = 0; i < a.size(); i++)
    {
        if (num == a[i].first)
        {
            if (a[i].second == 1)sum1--; else sum2--;
        }
        else
        {
            if (M < sum1 - sum2){ M = sum1 - sum2; ans = make_pair(sum1, sum2); }
            if (a[i].second == 1)sum1--; else sum2--;
            num = a[i].first;
        }
    }
    cout << ans.first << ":" << ans.second << endl;
}