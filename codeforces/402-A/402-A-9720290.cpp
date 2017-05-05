#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
    int k, a, b, v;
    cin >> k >> a >> b >> v;
    int sum = 0;
    int z;
    while (b != 0&&a>0)
    {
        if (b +1 <= k)
        {
            sum++;
            a -= (b+1)*v;
            b = 0;
        }
        else
        {
            sum++;
            b =b-k+1;
            a -= k*v;
        }
    }
    if (a > 0)
    {
        if (a%v == 0)sum = sum + a / v;
        else sum = sum + a / v + 1;
    }
    cout << sum;
}