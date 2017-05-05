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
struct ass{ int max1, max2, min1, min2, imax1, imax2, imin1, imin2; };
ass arr[MAX];
int main()
{
    //R_W;
    int n; cin >> n; vi a(n);
    for (int i = 0; i < n; i++){ cin >> a[i]; }
    int M = a[0], m = a[0], Mi = 0, mi = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>M){ M = a[i]; Mi = i; }if (a[i] < m){ m = a[i]; mi = i; }
        arr[i].max1 = M; arr[i].min1 = m; arr[i].imax1 = Mi; arr[i].imin1 = mi;
    }
    M = a[n - 1], m = a[n - 1], Mi = n - 1, mi = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i]>M){ M = a[i]; Mi = i; }if (a[i] < m){ m = a[i]; mi = i; }
        arr[i].max2 = M; arr[i].min2 = m; arr[i].imax2 = Mi; arr[i].imin2 = mi;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i].max1 > arr[i].min1&&arr[i].max1>arr[i].min2&&arr[i].imin1<arr[i].imax1&&arr[i].imax1<arr[i].imin2)
        {
            cout << "3\n";
            cout << arr[i].imin1 + 1 << " " << arr[i].imax1 + 1 << " " << arr[i].imin2 + 1 << endl;
            return 0;
        }
        if (arr[i].min1 < arr[i].max1&&arr[i].min1 < arr[i].max2&&arr[i].imax1<arr[i].imin1&&arr[i].imin1<arr[i].imax2)
        {
            cout << "3\n";
            cout << arr[i].imax1 + 1 << " " << arr[i].imin1 + 1 << " " << arr[i].imax2 + 1 << endl;
            return 0;
        }
    }
    cout << "0\n";
}