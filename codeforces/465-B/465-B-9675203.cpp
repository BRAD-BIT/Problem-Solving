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
    int sum = 0;
    int *a = new int[n];
    int to = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)to = i;
    }
    if (a[0] == 1)sum++;
    for (int i = 1; i <= to; i++)
    {
        if (a[i] == 1)sum++;
        if (a[i] == 0 && a[i - 1] == 1)sum++;
    }
    cout << sum;
}