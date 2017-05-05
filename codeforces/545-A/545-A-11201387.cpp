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
    int n; cin >> n; set<int>se;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x; cin >> x;
            if (x == 1)se.insert(i + 1);
            if (x == 2)se.insert(j + 1);
            if (x == 3){ se.insert(i + 1); se.insert(j + 1); }
        }
    }
    cout << n - se.size() << endl;
    for (int i = 0; i < n; i++)
    {
        bool test = true;
        for (set<int>::iterator it = se.begin(); it != se.end(); it++)
        {
            if (*it == i + 1)test = false;
        }
        if (test)cout << i + 1 << " ";
    }
}