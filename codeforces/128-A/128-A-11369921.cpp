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
struct node{ string s[8]; }; bool reached = 0; node temp;
int dr[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int check(int cur_r, int cur_c,int sum)
{
    if (cur_r < 0 || cur_c < 0 || cur_r>7 || cur_c>7)return 0;
    if (cur_r - sum >= 0)if (temp.s[cur_r-sum][cur_c] == 'S')return 0;
    if (cur_r - sum - 1 >= 0)if (temp.s[cur_r-sum-1][cur_c] == 'S')return 0;
    return 1;
}
void solve(int cur_r, int cur_c, int sum)
{
    if (sum >= 8 || reached){ reached = 1; return; }
    for (int i = 0; i < 9; i++)
    {
        if (check(cur_r + dr[i], cur_c + dc[i],sum))solve(cur_r + dr[i], cur_c + dc[i], sum + 1);
    }
}
int main()
{
    for (int i = 0; i < 8; i++)cin >> temp.s[i];
    solve(7, 0, 0);
    if (reached)cout << "WIN\n"; else cout << "LOSE\n";
}