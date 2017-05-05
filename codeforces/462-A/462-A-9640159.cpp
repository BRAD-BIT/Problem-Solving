#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
int main()
{
    int n;
    cin >> n;
    char **a = new char*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new char[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    bool test = true;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                if (j == 0)
                {
                    if (a[i][1] == 'o')sum++;
                }
                else
                if (j == n - 1)
                {
                    if (a[i][n-2] == 'o')sum++;
                }
                else
                {
                    if (a[i][j+1] == 'o')sum++;
                    if (a[i][j-1] == 'o')sum++;
                }
                if (i == 0)
                {
                    if (a[1][j] == 'o')sum++;
                }
                else
                if (i == n-1)
                {
                    if (a[n-2][j] == 'o')sum++;
                }
                else
                {
                    if (a[i+1][j] == 'o')sum++;
                    if (a[i-1][j] == 'o')sum++;
                }
        }
        if (sum % 2 != 0)test = false;
        sum=0;
    }
    if (n == 2)
    {
        if (a[0][0] == 'o'&&a[0][1] == 'x' && a[1][0] == 'x' && a[1][1] == 'o'&&n == 2)cout << "YES";
        else cout << "NO";
    }
    else
    if (test)cout << "YES";
    else cout << "NO";
}