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
    int n, c;
    cin >> n >> c;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = 0;
    for (int i = 0; i < n-1; i++)
    {
        int z = a[i] - a[i + 1] - c;
        if (z>max)max = z;
    }
    cout << max;
}