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
    int a, b;
    cin >> a >> b;
    int sum[] = { 0, 0, 0 };
    for (int i = 1; i < 7; i++)
    {
        int c = abs(i - a);
        int d = abs(i - b);
        if (c<d)sum[0]++;
        if (c == d)sum[1]++;
        if (d < c)sum[2]++;
    }
    cout << sum[0] << " " << sum[1] << " " << sum[2];
}