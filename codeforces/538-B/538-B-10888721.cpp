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
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<string>vv;
vector<ll>vl;
int main()
{
    ll n; cin >> n; vector<ll>vv;
    while (n)
    {
        string s = to_string(n);
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')ans += '0'; else ans += '1';
        }
        ll ds = stoll(ans);
        vv.push_back(ds);
        n -= ds;
    }
    sort(vv.begin(), vv.end());
    cout << vv.size() << endl;
    for (int i = 0; i < vv.size(); i++)cout << vv[i] << " "; cout << endl;
}