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

void intcrement_str(string &s)
{
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != 'z'){ s[i]++; for (int j = i + 1; j < s.length(); j++)s[j] = 'a'; return; }
    }
}
int main()
{
    string s1, s2; cin >> s1 >> s2;
    intcrement_str(s1);
    if (s1 < s2)cout << s1 << endl; else cout << "No such string\n";
}