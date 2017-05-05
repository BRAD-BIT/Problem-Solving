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
    int k;
    string s;
    cin >> k >> s;
    string s1 = s;
    sort(s.begin(), s.end());
    char x = s[0];
    int y = s.length();
    int sum1 = 0;
    bool test = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (x == s[i])
        {
            sum1++;
        }
        else
        if (sum1%k!=0)
        {
            test = false;
            break;
        }
        else
        {
            x = s[i];
            sum1 = 1;
        }
    }
    if (k == 1)cout << s1;
    else
    if (test&&sum1%k == 0)
    {
        x = s[0];
        string s2;
        int sum = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == x)sum++;
            else
            {
                for (int j = 0; j < sum / k; j++)
                {
                    s2 = s2 + x;
                }
                sum = 1;
                x = s[i];
            }
        }
        for (int i = 0; i < k; i++)
        {
            cout << s2;
        }
    }
    else cout <<-1;
}