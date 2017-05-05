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
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum = sum + a;
    }
    if (sum == 0)cout << 0;
    else if (sum>0)
    {
        if (sum < x)cout << 1;
        else
        {
            while (sum != 0)
            {
                sum = sum - x;
                sum1++;
                if (sum < 0)
                {
                    sum1--;
                    sum += x;
                    x--;
                }
            }
                cout << sum1;
        }
    }
    else
    {
        sum = -sum;
        if (sum < x)cout << 1;
        else
        {
            while (sum != 0)
            {
                sum = sum - x;
                sum1++;
                if (sum < 0)
                {
                    sum1--;
                    sum += x;
                    x--;
                }
            }
            cout << sum1;
        }
    }
}