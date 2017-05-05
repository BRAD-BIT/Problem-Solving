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
    int n, m;
    cin >> n >> m;
    int sum1 = 0;
    int sum2 = 1;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum1 = sum1 + a;
        if (sum1>m)
        {
            sum2++;
            sum1 = a;
        }
    }
    cout << sum2;
}