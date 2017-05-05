#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
vector<vector<int>>graph;
ll a[100017]; int Sum[100017] = { 0 };
int main()
{
    ll n, m, sum = 0; cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        ll type, x, y; cin >> type;
        if (type == 1)
        {
            cin >> x >> y; a[x - 1] = y; Sum[x - 1] = -sum;
        }
        else
        if (type == 2)
        {
            cin >> y; sum += y;
        }
        else
        {
            cin >> x; cout << a[x - 1]+sum+Sum[x-1] << endl;
        }
    }
}