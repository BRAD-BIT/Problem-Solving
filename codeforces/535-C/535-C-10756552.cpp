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
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
ll s[2000000]; ll l, t, m;
ll sum(int end)
{
    return ((s[l - 1] + s[end])*(end - l + 2) / 2);
}
ll Binary_Search(int low, int high)
{
    ll mid; ll ans = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (sum(mid) == t*m&&s[mid]<=t)return mid;
        else
        if (sum(mid) > t*m)
        {
            high = mid - 1;
        }
        else
        if (sum(mid)<t*m)
        {
            if (s[mid] == t)
            {
                return mid;
            }
            else
            if (s[mid] > t)
            {
                high = mid - 1;
            }
            else
            if (s[mid] < t)
            {
                ans = mid;
                low = mid + 1;
            }

        }
    }
    return ans;
}
int main()
{
    ll A, B, n; cin >> A >> B >> n;
    for (int i = 0; i < 2000000; i++){ s[i] = A + i*B; }
    for (int i = 0; i < n; i++)
    {
        cin >> l >> t >> m;
        if (s[l - 1]>t)cout << -1 << endl;
        else cout << Binary_Search(l - 1, 2000000) + 1 << endl;
    }
}