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
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *y = &a[n - 1];
    int *x = &a[0];
    int sum1 = 0;
    int sum2 = 0;
    int j = 0;
    while (n != 0)
    {
        if (j % 2 == 0)
        {
            if (*y > *x)
            {
                sum1 = sum1 + *y;
                y -= 1;
                n--;
            }
            else
            if (*x >= *y)
            {
                sum1 = sum1 + *x;
                x += 1;
                n--;
            }
        }
        else
        {
            if (*y > *x)
            {
                sum2 = sum2 + *y;
                y -= 1;
                n--;
            }
            else
            if (*x >= *y)
            {
                sum2 = sum2 + *x;
                x += 1;
                n--;
            }
        }
        j++;
    }
    cout << sum1 << " " << sum2;
}