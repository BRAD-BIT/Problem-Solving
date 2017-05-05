#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>  
#include<stack>
#include<queue>
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
    int indexD1 = (n / 2) ;
    int indexD2 = (n / 2) ;
    for (int i = 0; i < n/2; i++)
    {
        if (i != 0)
        {
            indexD1 = indexD1 - 1;
            indexD2 = indexD2 +1;
        }
        for (int j = 0; j < n; j++)
        {
            if (j >= indexD1&&j <= indexD2)
            {
                a[i][j] = 'D';
                a[n-1-i][j] = 'D';
            }
            else
            {
                a[i][j] = '*';
                a[n - 1 - i][n - 1 - j] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[(n / 2)][i] = 'D';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}