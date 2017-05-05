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
    //R_W;
    int v1, v2, t, d; cin >> v1 >> v2 >> t >> d; int f = v1;
    int distance = v1 + v2; t -= 2; int x = t;
    v1 = min(v1, v2);
    v2 = max(f, v2);
    for (int i = 0; i < t; i++)
    {
        if (x ==1)
        {
            if (v1>v2)
            {
                if (v1 >= v2 + d)
                {
                    v1 = v2 + d;
                }
                else
                {
                    int m = d;
                    while (d--)
                    {
                        v1++;
                        if (v1>v2+m){ v1--; break; }
                    }
                }
            }
            else
            {
                int m = d;
                while (d--)
                {
                    v1++;
                    if (v1>v2 + m){ v1--; break; }
                }
            }
        }
        else
        {
            if (v1 - x*d > v2)
            {
                int m = d;
                while (m--)
                {
                    v1--;
                    if (v1 - x*d==v2){ break; }
                }
            }
            int m = d;
            while (m--)
            {
                v1++;
                if (v1 - x*d>v2){ v1--; break; }
            }
        }
        distance += v1;
        x--;
    }
    cout << distance << endl;
}