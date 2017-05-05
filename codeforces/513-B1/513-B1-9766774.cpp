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
int b[100000][9];
int main()
{
    int n, m;
    cin >> n >> m;
    int y = n;
    long long t = 1;
    while (y != 0)
    {
        t = t*y;
        y--;
    }
    int *a = new int[n];
    for (int i = 0; i <n; i++)
    {
        a[i] = i + 1;
    }
    int sum = 0;
    int max = 0;
    int m1 = 0;
    while (t != 0)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int min = a[i];
                for (int v = i; v <= j; v++){ if (a[v] < min)min = a[v]; }
                sum += min;
            }
        }
        if (sum>max){ max = sum; }
        b[m1][0] = sum;
        for (int h = 1; h <= n; h++)
        {
            b[m1][h] = a[h - 1];
        }
        m1++;
        t--;
        next_permutation(a, a + n);
    }
    int k = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (b[i][0] == max)k++;
        if (k == m)
        {
            for (int l = 1; l <= n; l++)cout << b[i][l] << " ";
            return 0;
        }
    }
    return 0;
}