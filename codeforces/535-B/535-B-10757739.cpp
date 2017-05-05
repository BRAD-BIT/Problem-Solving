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
vector<string>vv;
void lucky(string s)
{
    if (s.length() == 10) return;
    if (s != "")vv.push_back(s);
    lucky(s + '4');
    lucky(s + '7');
}
bool comp(string a, string b)
{
    if (a.length() != b.length())return a.length() < b.length();
    else
        return a < b;
}
int main()
{
    ll n; cin >> n; string s = to_string(n); int i = 0; lucky("");
    sort(vv.begin(), vv.end(),comp);
    for (int i = 0; i < vv.size(); i++){ if (s == vv[i])cout << i + 1 << endl; }
}