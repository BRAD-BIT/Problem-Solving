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
    long long n, m;
    cin >> n >> m;
    long long max = ((n - m + 1)*(n - m)) / 2;
    long long min;
    if (n%m == 0)min = (m*(n / m)*(n / m - 1)) / 2;
    else
    {
        long double x = n / m;
        long double y = n%m;
        for (int i = 1; i <= m; i++)
        {
            y--;
            if (y == 0)
            {
                y = i;
                break;
            }
        }
        min = y*(((x + 1)*(x)) / 2) + (m - y)*(((x)*(x - 1)) / 2);
    }
    cout << min << " " << max;
}