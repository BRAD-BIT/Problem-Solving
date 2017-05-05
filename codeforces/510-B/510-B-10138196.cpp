#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
char a[51][51]; int n, m;
bool cycle(int l,int r, int x, int y, int i, int j, int b[51][51], char c)
{
    if (i >= n || j >= m || i < 0 || j < 0 || c != a[i][j] || b[i][j] == 1)return false;
    if (i == l&&j == r)
    {
        if (b[i][j] != -1)return true;
    }
    b[i][j]++;
    if(j+1!=y)if (cycle(l, r, i, j, i, j + 1, b, c))return true;
    if(j-1!=y)if (cycle(l, r, i, j, i, j - 1, b, c))return true;
    if(i-1!=x)if (cycle(l, r, i, j, i - 1, j, b, c))return true;
    if(i+1!=x)if (cycle(l, r, i, j, i + 1, j, b, c))return true;
    return false;
}
int main()
{
    int c[51][51]; cin >> n >> m; for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){ cin >> a[i][j]; c[i][j] = 0; }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        c[i][j] = -1;
        if (cycle(i, j, i, j, i, j, c, a[i][j]))
        {
            cout << "Yes" << endl; return 0;
        }
        c[i][j] = 0;
        for (int z = 0; z < n; z++)for (int d = 0; d < m; d++){c[z][d] = 0;}
    }
    cout << "No" << endl;
}