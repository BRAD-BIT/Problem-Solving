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
int n1, n2, x, y;
bool calc(ll i)
{
    ll num = i;ll z = num / (x*y);
    ll v1 = i / y - z;
    ll v2 = i / x - z;
    num = i - (v1 + v2) - z;
    if (v1 + v2 + num >= n1 + n2 &&v1 + num >= n1&&v2 + num >= n2)return 1;
    return false;
}
ll binary_search()
{
    ll start = 0; ll end = 1e18; ll first=-1;
    ll mid = (start + end) / 2;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (!calc(mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
            first = mid;
        }
    }
    return first;
}
int main()
{
    cin >> n1 >> n2 >> x >> y;
    cout << binary_search() << endl;
}