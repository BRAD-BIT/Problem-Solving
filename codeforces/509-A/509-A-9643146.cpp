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
    int **a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[0][i] = 1;
    }
    int max = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            a[i][j] = a[i - 1][j]+a[i][j-1];
            if (a[i][j]>max)max = a[i][j];
        }
    }
    cout << max;
}