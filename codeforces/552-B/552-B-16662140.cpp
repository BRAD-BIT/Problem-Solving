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
    int n; cin >> n;
    int a[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
    int b[] = { 0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 1000000000 };
    ll sum = 0;
    for (int i = 1; i <= 10; i++)
    {if (n >= b[i]){ ll x = (b[i] - a[i] + 1); x *= i; sum += x; }else{ ll x = (n - b[i - 1]); x *= i; sum += x; break; }}
    cout << sum << endl;
}