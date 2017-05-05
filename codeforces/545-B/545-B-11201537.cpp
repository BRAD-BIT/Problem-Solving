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
    string s1, s2, s3; cin >> s1 >> s2; int sum = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])sum++;
    }
    if (sum % 2 != 0){ cout << "impossible" << endl; return 0; }
    int x = 0, y = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])s3 += s1[i];
        else
        {
            if (x < sum / 2){ s3 += s1[i]; x++; }
            else
            if (y < sum / 2){ s3 += s2[i]; y++; }
        }
    }
    cout << s3 << endl;
}