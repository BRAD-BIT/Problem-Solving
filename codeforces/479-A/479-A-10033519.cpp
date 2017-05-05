#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int sum[4];
    sum[0] = a + b + c;
    sum[1] = a*b*c;
    sum[2] = (a + b)*c;
    sum[3] = (b + c)*a;
    int max = sum[0];
    for (int i = 0; i < 4; i++)
    {
        if (sum[i]>max)max = sum[i];
    }
    cout << max;
}