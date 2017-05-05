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
int main()
{
    int n; string s; cin >> n >> s; int sumx = 0, sumX = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')sumx++;
        else sumX++;
    }
    if (sumx>sumX)
    {
        int y = sumx - n / 2;
        cout << y << endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'x'){ s[i] = 'X'; y--; }
            if (y == 0)break;
        }
        cout << s << endl;
    }
    else
    if (sumx<sumX)
    {
        int y = sumX - n / 2;
        cout << y << endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'X'){ s[i] = 'x'; y--; }
            if (y == 0)break;
        }
        cout << s << endl;
    }
    else
    if (sumx == sumX){ cout << 0 << endl << s << endl; }
}