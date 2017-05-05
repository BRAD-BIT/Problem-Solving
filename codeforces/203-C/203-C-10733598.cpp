#define _CRT_SECURE_NO_WARNINGS
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
#include<array>
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
struct ass{ long long value, index; };
bool comp(ass a, ass b)
{
    return a.value < b.value;
}
int main()
{
    ll n, d, a, b; cin >> n >> d >> a >> b;
    vector<ass>vv;
    vector<int>vv2;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        ass d;
        d.value = x*a + y*b;
        d.index = i+1;
        vv.push_back(d);
    }
    sort(vv.begin(), vv.end(),comp);
    ll sum = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum += vv[i].value;
        if (sum <= d)
        {
            sum2++;
            vv2.push_back(vv[i].index);
        }
        else break;
    }
    cout << sum2 << endl;
    for (int i = 0; i < vv2.size(); i++)cout << vv2[i] << " ";
}