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
    string s;
    cin >> s;
    int sum = 0;
    while (s.length()!=1)
    {
        int x = s.length() - 1;
        if (s[x] ==  '0')s.erase(x , 1);
        else
        {
            s[x] = '0';
            for (int i = x - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                    break;
                }
                else
                {
                    s[i] = '0';
                }
            }
        }
        sum++;
    }
    if (s[0] == '0')sum++;
    cout << sum;
}