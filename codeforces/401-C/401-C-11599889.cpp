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
bool check(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, 3) == "111" || s.substr(i, 2) == "00")return 0;
    }
    return 1;
}
int main()
{
    int n, m, m2, n2; cin >> m >> n;
    string ans1, ans2; n2 = n; m2 = m;
    while (!(n <= 0 && m <= 0))
    {
        if (n - 2 >= m){ ans1+="11"; n -= 2;}
        else
        if(n>=m){ ans1+="1"; n--;}
        if (m != 0){ ans1+='0'; m--; }
    }
    while (!(n2 <= 0 && m2 <= 0))
    {
        if (m2 != 0){ ans2 += '0'; m2--; }
        if (n2 - 2 >= m2){ ans2 += "11"; n2 -= 2; }
        else
        if (n2 >= m2){ ans2 += "1"; n2--; }
    }
    if (check(ans1))cout << ans1 << endl;
    else
    if (check(ans2))cout << ans2 << endl;
    else
    cout << -1 << endl;
}