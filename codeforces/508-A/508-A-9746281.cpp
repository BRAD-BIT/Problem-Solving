#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
    int n, m, k, x, y;
    cin >> n >> m >> k;
    char **a = new char*[n];
    for (int i = 0; i < n; i++)a[i] = new char[m];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)a[i][j] = 'w';
    for (int i = 0; i < k; i++)
    {
        bool test1 = false, test2 = false, test3 = false, test4 = false;
        cin >> x >> y;
        x--, y--;
        a[x][y] = 'b';
        if (x == 0 && y != 0 && y != m - 1)
        {
            if (a[1][y] == 'b')
            {
                if ((a[0][y - 1] == 'b'&&a[1][y - 1] == 'b') || (a[0][y + 1] == 'b'&&a[1][y + 1] == 'b'))
                {
                    cout << i + 1;
                    return 0;
                }
            }
        }
        else
        if (x == n - 1 && y != 0 && y != m - 1)
        {
            if (a[n - 2][y] == 'b')
            {
                if ((a[n - 1][y - 1] == 'b'&&a[n - 2][y - 1] == 'b') || (a[n - 1][y + 1] == 'b'&&a[n - 2][y + 1] == 'b'))
                {
                    cout << i + 1;
                    return 0;
                }
            }
        }
        else
        if (y == 0 && x != 0 && x != n - 1)
        {
            if (a[x][1] == 'b')
            {
                if ((a[x - 1][0] == 'b'&&a[x - 1][1] == 'b') || (a[x + 1][0] == 'b'&&a[x + 1][1] == 'b'))
                {
                    cout << i + 1;
                    return 0;
                }
            }
        }
        else
        if (y == m - 1 && x != 0 && x != n - 1)
        {
            if (a[x][m - 2] == 'b')
            {
                if ((a[x - 1][m - 1] == 'b'&&a[x - 1][m - 2] == 'b') || (a[x + 1][m - 1] == 'b'&&a[x + 1][m - 2] == 'b'))
                {
                    cout << i + 1;
                    return 0;
                }
            }
        }
        else
        if (x == 0 && y == 0)
        {
            if (a[0][1] == 'b'&&a[1][1] == 'b'&&a[1][0] == 'b')
            {
                cout << i + 1;
                return 0;
            }
        }
        else
        if (x == 0 && y == m - 1)
        {
            if (a[0][m - 2] == 'b'&&a[1][m - 2] == 'b'&&a[1][m - 1] == 'b')
            {
                cout << i + 1;
                return 0;
            }
        }
        else
        if (x == n - 1 && y == 0)
        {
            if (a[n - 1][1] == 'b'&&a[n - 2][1] == 'b'&&a[n - 2][0] == 'b')
            {
                cout << i + 1;
                return 0;
            }
        }
        else
        if (x == n - 1 && y == m - 1)
        {
            if (a[n - 1][m - 2] == 'b'&&a[n - 2][m - 2] == 'b'&&a[n - 2][m - 1] == 'b')
            {
                cout << i + 1;
                return 0;
            }
        }
        else
        {
            if (a[x][y + 1] == 'b'&&a[x - 1][y] == 'b'&&a[x - 1][y + 1] == 'b')
            {
                cout << i + 1;
                return 0;
            }
            else
            if (a[x][y + 1] == 'b'&&a[x + 1][y] == 'b'&&a[x + 1][y + 1] == 'b')
            {
                cout << i + 1;
                return 0;
            }
            else
            if (a[x][y - 1] == 'b'&&a[x - 1][y] == 'b'&&a[x - 1][y - 1] == 'b')
            {
                cout << i + 1;
                return 0;
            }
            else
            if (a[x][y - 1] == 'b'&&a[x + 1][y] == 'b'&&a[x + 1][y - 1] == 'b')
            {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << 0;
}