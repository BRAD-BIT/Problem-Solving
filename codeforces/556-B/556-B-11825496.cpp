#include<string>
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
int main()
{
    int n; cin >> n; int a[1100]; for (int i = 0; i<n; i++)cin >> a[i]; int r = 0;
    for (int i = 0; i<50000; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (j % 2 == 0){ a[j]++; if (a[j] == n)a[j] = 0; }else{ a[j]--; if (a[j] == -1)a[j] = n - 1; }
        }
        bool test = true;
        for (int j = 0; j<n; j++)if (a[j] != j){ test = false; break; }
        if (test){ cout << "YES\n"; return 0; }
    }
    cout << "NO\n";
}