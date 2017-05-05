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
    ll n; cin >> n; ll a[107];
    for (int i = 0; i < n; i++)cin >> a[i];
    vector<int>v;
    for (int from = 0; from < n; from++)
    {
        for (int to = from; to < n; to++)
        {
            ll ans = a[from];
            for (int i = from+1; i <= to; i++)
            {
                ans = ans^a[i];
            }
            v.push_back(ans);
        }
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << endl;
}