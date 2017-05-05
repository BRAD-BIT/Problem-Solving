//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1

using namespace std;
int main()
{
    int n; string s; cin >> n >> s; ll ans = 0;
    ll a[50]; a[0] = 0, a[1] = 1,a[2] = 3;
    for (int i = 3; i < n; i++)a[i] = 2 * a[i-1]+1;
    for (int i = 0; i < n; i++)if (s[i] == 'B')ans += a[i]+1; cout << ans << endl;
}