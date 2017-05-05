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
    int n, m;
    cin >> n >> m;
    bool test = true;
    while (test)
    {
        for (int i = 1; i <= n; i++)
        {
            m -= i;
            if (m == 0)
            {
                test = false;
                break;
            }
            else
            if (m < 0)
            {
                m += i;
                test = false;
                break;
            }
        }
    }
    cout << m;
}