#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m > n)cout << -1;
    else
    if (m == n)cout << m;
    else
    {
        bool test = false;
        if (n % 2 == 0)
        {
            int z = n / 2;
            for (int i = z; i < n; i++)
            {
                if (i%m == 0)
                {
                    test = true;
                    cout << i;
                    break;
                }
            }
        }
        else
        {
            int z = (n / 2) + 1;
            for (int i = z; i < n; i++)
            {
                if (i%m == 0)
                {
                    test = true;
                    cout << i;
                    break;
                }
            }
        }
        if (!test)cout << -1;
    }
}