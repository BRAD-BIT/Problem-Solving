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
    int *a= new int[n];
    int sumO = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)sumO++;
    }
    int sum1 = sumO;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            for (int v = j; v >= i; v--)
            {
                if (a[v] == 1)sum1--;
                else sum1++;
            }
            if (sum1>max)max = sum1;
            sum1 = sumO;
        }
    }
    cout << max;
}