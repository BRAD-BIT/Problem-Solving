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
#include <iterator>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
char a[151][151]; int n, m;
bool test(int x)
{
    if (x + 1 == n)return false;
    for (int i = x + 1; i < n; i++)
    for (int j = 0; j < m; j++)
    if (a[i][j] == 'W')return true;
    return false;
}
void res(int &aa, int &b, int &c,int &d,char &e)
{
    if (e == 'R')
    {
        int max = b;
        for (int i = b; i < m; i++)
        {
            if (a[aa][i] == 'W'){ max = i; d--; a[aa][i] = 'G'; }
            if(aa<n-1)if (a[aa+1][i] == 'W'){ max = i; }
        }
        c += (max - b); if (test(aa))c++;
        aa++; b = max;
    }
    else
    {
        int max = b;
        for (int i = b; i >= 0; i--)
        {
            if (a[aa][i] == 'W'){ max = i; d--; a[aa][i] = 'G'; }
            if (aa<n - 1)if (a[aa + 1][i] == 'W'){ max = i; }
        }
        c += (b - max); if (test(aa))c++;
        aa++; b = max;
    }
    if (e == 'R')e = 'L'; else e = 'R';
}
int main()
{
    cin >> n >> m; int weed = 0, moves = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){ cin >> a[i][j]; if (a[i][j] == 'W')weed++; }
    int x = 0, y = 0; char dir = 'R';
    while (weed)
    {
        res(x, y, moves, weed, dir);
    }
    cout << moves << endl;
}