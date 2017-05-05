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
    long long n, t, c, x, sum1 = 0, sum2 = 0; cin >> n >> t >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x>t)
        {
            sum1 -= (c - 1);
            if (sum1 > 0)sum2 += sum1;
            sum1 = 0;
        }
        else sum1++;
    }
    sum1 -= (c - 1);
    if (sum1 > 0)sum2 += sum1;
    cout << sum2;
}