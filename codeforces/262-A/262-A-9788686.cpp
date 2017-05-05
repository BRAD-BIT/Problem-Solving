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
    int n, k, sum1 = 0, sum2 = 0;; string s; cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        sum1 = 0; cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '4' || s[j] == '7')sum1++;
        }
        if (sum1 <= k)sum2++;
    }
    cout << sum2;
}