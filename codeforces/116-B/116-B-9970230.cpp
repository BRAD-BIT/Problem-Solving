#include<iostream>
#include<string>
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
int n, m;
bool test(int i, int j)
{
    if ((i >= 0 && i < n) && (j >= 0 && j < m))return true;
    else return false;
}
int main()
{
    cin >> n >> m; char a[10][10]; for (int i = 0; i < n; i++){ for (int j = 0; j < m; j++)cin >> a[i][j]; }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool test2 = true;
            if (a[i][j] == 'P')
            {
                if (test(i, j + 1) && test2){ if (a[i][j + 1] == 'W'){ sum++; test2 = false; a[i][j + 1] = '.'; } }
                if (test(i, j - 1) && test2){ if (a[i][j - 1] == 'W'){ sum++; test2 = false; a[i][j - 1] = '.'; } }
                if (test(i + 1, j) && test2){ if (a[i + 1][j] == 'W'){ sum++; test2 = false; a[i + 1][j] = '.'; } }
                if (test(i - 1, j) && test2){ if (a[i - 1][j] == 'W'){ sum++; test2 = false; a[i - 1][j] = '.'; } }
            }
        }
    }
    cout << sum << endl;
}