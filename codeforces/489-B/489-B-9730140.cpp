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
    int n, m;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    int *b = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int z = abs(a[i] - b[j]);
            if (z == 0 || z == 1)
            {
                sum++;
                b[j] = 2200;
                break;
            }
        }
    }
    cout << sum;
}