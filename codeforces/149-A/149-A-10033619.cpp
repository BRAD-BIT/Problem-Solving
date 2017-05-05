#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>  
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[12];
    int sum3 = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> a[i];
        sum3 += a[i];
    }
    sort(a, a + 12, greater<int>());
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 12; i++)
    {
        sum1 = sum1 + a[i];
        sum2++;
        if (sum1 >= n)break;
    }
    if (n>sum3)cout << -1;
    else
    if (n == 0)cout << 0;
    else cout << sum2;
}