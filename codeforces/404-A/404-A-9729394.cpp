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
    bool test1 = true;
    bool test2 = true;
    char s1 = a[0][0];
    char s2 = a[0][1];
    for (int j = 0; j < n; j++)
    {
        if (a[j][j] != s1 || a[j][n - j - 1] != s1)test1 = false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i&&j != n - i - 1)
            {
                if (a[i][j] != s2)test2 = false;
            }
        }
    }
    if (test1&&test2&&(s1!=s2))cout << "YES";
    else cout << "NO";
}