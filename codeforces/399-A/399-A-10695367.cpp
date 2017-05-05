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
    int n, p, k; cin >> n >> p >> k;
    vector<int>a, b; int m = p - 1;
    for (int i = 0; i < k; i++)
    {
        if (m >0)a.push_back(m);
        m--;
    }
    m = p+1;
    for (int i = 0; i < k; i++)
    {
        if (m <=n)b.push_back(m);
        m++;
    }
    reverse(a.begin(), a.end());
    if (a.size() != 0){ if (a[0] != 1)cout << "<< "; }
    for (int i = 0; i < a.size(); i++)cout << a[i] << " "; cout << "(" << p << ") "; for (int i = 0; i < b.size(); i++)cout << b[i] << " ";
    if (b.size() != 0){ if (b[b.size() - 1] != n)cout << ">>"; }
}