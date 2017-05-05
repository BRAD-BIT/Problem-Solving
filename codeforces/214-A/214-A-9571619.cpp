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
    int n, m;
    cin >> n >> m;
    int z;
    if (m > n)z = m;
    else z = n;
    int sum = 0;
    for (int i = 0; i <= z; i++)
    {
        for (int j = 0; j <= z; j++)
        {
            if (i*i + j == n&&i + j*j == m)sum++;
        }
    }
    cout << sum;
}