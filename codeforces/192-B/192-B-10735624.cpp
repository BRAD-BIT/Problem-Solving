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
#define R_W        R_("input.txt"),W_("output.txt")0
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int main()
{
    int n; cin >> n; int a[1007];
    for (int i = 0; i < n; i++)cin >> a[i];
    if (n == 1)cout << a[0];
    for (int day = 1; day <= 1000; day++)
    {
        for (int i = 0; i < n; i++)
        {
            a[i]--;
        }
        for (int i = 0; i < n-1; i++)
        {
            if (a[i] <= 0 && a[i + 1] <= 0||a[n-1]<=0||a[0]<=0){ cout << day << endl; return 0; }
        }
    }
}