#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 2 * n - 1;
    for (int i = 1; i < n - 1; i++)
    {
        sum = sum + (i+1) * (n - (i + 1));
    }
    cout << sum;
}