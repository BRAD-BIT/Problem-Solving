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
    int *s = new int[n-1];
    for (int i = 0; i < n-1; i++)
    {
        cin >> s[i];
    }
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a - 1; i < b-1; i++)
    {
        sum = sum + s[i];
    }
    cout << sum;
}