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
vector<int>v1;
vector<int>v2;
vector<int>v3;
bool a7a(string x)
{
    int n = x.length();for (int i = 0; i < n / 2; ++i){if (x[i] != x[n-1-i])return 0;}return 1;
}
 
int main()
{
    string x;cin >> x;int k,n=x.length();cin >> k;
    if (n%k != 0)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i += n/k)
    {
        if (!a7a(x.substr(i, n/k)))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}