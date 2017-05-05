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
    int n, m, k;
    cin >> n >> m >> k;
    int *a = new int[m + 1];
    for (int i = 0; i <= m; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int sum1 = 0;
        for (int j = 0; j < m; j++)
        {
            sum1 = 0;
            bitset<70>x(a[m]);
            bitset<70>y(a[j]);
            for (int v = 0; v < n; v++)
            {
                if (x[v] != y[v])sum1++;
            }
            if (sum1 <= k)sum++;
        }
    cout << sum;
}