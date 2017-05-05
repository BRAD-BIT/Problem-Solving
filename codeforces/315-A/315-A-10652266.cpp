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
struct bottle{ int a, b, c = 0; };
int main()
{
    int n; cin >> n;bottle a[107];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a >> a[i].b;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (a[i].b == a[j].a)a[j].c = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].c == 0)sum++;
    }
    cout << sum << endl;
}