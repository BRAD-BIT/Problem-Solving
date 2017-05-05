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
int a[1000000] = { 0 };
int main()
{
    string s; int m; cin >> s >> m;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        a[x-1]++;
    }
    for (int i = 0; i < s.length()/2; i++)
    {
        if (a[i] %2 != 0)
        {
            swap(s[i], s[s.length() - i - 1]);
            for (int j = i+1; j < s.length()/2; j++)
            {
                i = j;
                if (a[j] % 2 == 0)
                {
                    swap(s[j], s[s.length()- j - 1]);
                }
                else break;
            }
        }
    }
    cout << s << endl;
}