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
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    int sum1 = 0;
    int sum2 = sum;
    for (int i = 0; i < 5; i++)
    {
        sum2 += i + 1;
        while (true)
        {
            sum2 -= (n + 1);
            if (sum2 == 0){ sum1++; break; }
            if (sum2 == 1)break;
            else
            if (sum2 > 0 && sum2<n + 1){ sum1++; break; }
        }
        sum2 = sum;
    }
    cout << sum1;
}