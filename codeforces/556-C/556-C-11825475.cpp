#include<string>
#include<vector>
#include<iostream>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define  oo  1e9
using namespace std;
vector<vector<int>>v;
int main()
{
    int n, k; cin >> n >> k; v.resize(k); int ans = 0; int sum = 0;
    for (int i = 0; i < k; ++i)
    {
        int a, b; cin >> a;
        for (int j = 0; j < a; ++j)cin >> b, v[i].push_back(b);
    }
    for (int i = 0; i < k; ++i)
    {
        if (v[i][0] == 1)
        {
            int a = 1;
            for (int j = 0; j < v[i].size() - 1; ++j)if (v[i][j + 1] - v[i][j] == 1)a++; else break;
            ans += 2 * v[i].size() - 2 * a + 1;
        }
        else
        ans += 2*v[i].size() - 1;
        
    }
    ans--;
    cout << ans << endl;
}