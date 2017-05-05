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
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int sum1 = 1;
    int sum2 = 1;
    int sum = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            sum1++;
        }
        else
        {
            if (sum1 > sum2)
            {
                sum2 = sum1;
            }
            sum1 = 1;
            sum++;
        }
    }
    if (sum1 > sum2)
    {
        sum2 = sum1;
    }
    cout << sum2 << " " << sum;
}