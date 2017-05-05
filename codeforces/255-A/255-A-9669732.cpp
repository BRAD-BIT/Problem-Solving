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
    int a;
    int sum[] = { 0, 0, 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum[i % 3] += a;
    }
    int max = sum[0];
    for (int i = 0; i < 3; i++)
    {
        if (sum[i]>max)max = sum[i];
    }
    if (max == sum[0])cout << "chest";
    else
    if (max == sum[1])cout << "biceps";
    else cout << "back";
}