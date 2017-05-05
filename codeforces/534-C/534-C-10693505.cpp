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
ll arr[1000007];
int main()
{
    //R_W;
    ll n, a; cin >> n >> a; ll sum_max = 0, sum_min = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; sum_max += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        
        ll Min, Max;
        Max = a - sum_min + 1; if (Max>arr[i])Max = arr[i];
        if (sum_min == a ||sum_max - arr[i]+1>=a)Min = 1; else if (sum_max - arr[i] < a)Min = a - (sum_max - arr[i]);
        ll ans = arr[i] - Max + Min - 1;
        cout << ans << " ";
    }
    cout << endl;
}
//v