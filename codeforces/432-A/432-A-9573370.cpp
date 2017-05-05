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
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int z = a[i] + k;
        if (z <= 5)sum++;
    }
    cout << sum / 3;
}