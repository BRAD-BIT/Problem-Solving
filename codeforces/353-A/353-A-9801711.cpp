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
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
    int n, sum1 = 0, sum2 = 0, x, y; cin >> n; bool test = true; for (int i = 0; i < n; i++){ cin >> x >> y; sum1 += x; sum2 += y; if (!((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0)))test = false; }
    if (sum1 % 2 == 0 && sum2 % 2 == 0)cout << 0;
    else
    if ((sum1 % 2 == 0 && sum2 % 2 != 0) || (sum1 % 2 != 0 && sum2 % 2 == 0))cout << -1;
    else
    {
        if (test)cout << -1;
        else
        {
            if (sum1%2!=0 &&sum2%2!=0)cout << 1;
            else cout << -1;
        }
    }
}