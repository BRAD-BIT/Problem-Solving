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
int MOM2[4][10000001];
ll dp(ll value)
{
    MOM2[0][0] = 0; MOM2[1][0] = 0; MOM2[2][0] = 0; MOM2[3][0] = 1;
    for (ll i = 1; i < 10000001; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j != 0)MOM2[j][i] += MOM2[0][i - 1]; MOM2[j][i] %= 1000000007;
            if (j != 1)MOM2[j][i] += MOM2[1][i - 1]; MOM2[j][i] %= 1000000007;
            if (j != 2)MOM2[j][i] += MOM2[2][i - 1]; MOM2[j][i] %= 1000000007;
            if (j != 3)MOM2[j][i] += MOM2[3][i - 1]; MOM2[j][i] %= 1000000007;
        }
    }
    return MOM2[3][value];
}
int main()
{
    ll n; cin >> n;
    ll ans = dp(n);
    cout << ans << endl;
}