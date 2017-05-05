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
    int *a = new int[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int s, t;
    cin >> s >> t;
    if (t < s)swap(s, t);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = s; i < t; i++)
    {
        sum1 = sum1+ a[i];
    }
    sum2 = sum - sum1;
    if (sum1 < sum2)cout << sum1;
    else cout << sum2;
}