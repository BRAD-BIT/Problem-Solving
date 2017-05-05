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
    int n, m, k;
    cin >> n >> m >> k;
    int *a = new int[n];
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)sum1++;
        else sum2++;
    }
    int M = m - sum1;
    int K = k - sum2;
    if (K >= 0 && M >= 0)cout << 0;
    else
    if (M>0 && M + K >= 0)cout << 0;
    else
    if (M > 0 && M + K < 0)cout << -(M + K);
    else
    if (M < 0 && K < 0)cout << -(M + K);
    else
    if (M == 0 && K < 0)cout << -K;
    else 
    if (M<0 && k>0)cout << -M;
}