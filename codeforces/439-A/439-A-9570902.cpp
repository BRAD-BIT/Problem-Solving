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
    int n, d;
    cin >> n >> d;
    int *a = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    sum = sum + (n - 1) * 10;
    if (sum>d)cout << -1;
    else
    {
        int jok = (n - 1) * 2 + (d - sum) / 5;
        cout << jok;
    }
}