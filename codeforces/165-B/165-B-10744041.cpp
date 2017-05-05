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
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")0
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int line(int v, double k)
{
    ll ans = v; int i = 1;
    while (v/pow(k,i)>0)
    {
        ans += floor(v / pow(k, i));
        i++;
    }
    return ans;
}
int binary_search(int n,int k)
{
    ll low = 0, high = 1000000000, mid, ans = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (line(mid, k) == n)return mid;
        else if (line(mid, k) > n)
        {
            ans = mid;
            high = mid-1 ;
        }
        else
        {
            low = mid+1 ;
        }
    }
    return ans;
}
int main()
{
    ll n, k; cin >> n >> k;
    ll ans = binary_search(n, k);
    cout << ans << endl;
}