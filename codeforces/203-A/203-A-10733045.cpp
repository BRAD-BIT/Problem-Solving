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
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int main()
{
    int x, t, a, b, da, db; cin >> x >> t >> a >> b >> da >> db;
    int scoreA[10000];
    int scoreB[10000];
    int an = 0;
    while (an<t)
    {
        scoreA[an] = a - an*da;
        scoreB[an] = b - an*db;
        an++;
    }
    if (x == 0){ cout << "YES"; return 0; }
    for (int i = 0; i <= an; i++)
    {
        for (int j = 0; j <= an; j++)
        {
            {
                if (scoreA[i] + scoreB[j] == x){ cout << "YES"; return 0; }
            }
        }
    }
    for (int i = 0; i <= an; i++)if (scoreA[i] == x){ cout << "YES"; return 0; }
    for (int i = 0; i <= an; i++)if (scoreB[i] == x){ cout << "YES"; return 0; }
    cout << "NO";
}