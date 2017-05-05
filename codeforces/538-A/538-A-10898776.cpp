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
int main()
{
    string s; cin >> s;
    string temp;
    string s1, s2, s3;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            s1 = s.substr(0, i);
            s2 = s.substr(i, j);
            s3 = s.substr(j, s.length());
            if (s1 + s3 == "CODEFORCES" || s1 + s2 == "CODEFORCES" || s2 + s3 == "CODEFORCES"){ cout << "YES"; return 0; }
        }
    }
    cout << "NO";
}