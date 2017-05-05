#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    int carry = 0;
    string s3 = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    string s2 = s1;
    for (int i = 0; i < s1.length(); i++)
    {
        int z = s1[i] + s3[i] + carry - 96;
        if (z == 0)
        {
            carry = 0;
            s2[i] = '0';
        }
        else
        if (z == 1)
        {
            carry = 0;
            s2[i] = '1';
        }
        else
        if (z == 2)
        {
            carry = 1;
            s2[i] = '0';
        }
        else 
        if (z == 3)
        {
            carry = 2;
            s2[i] = '1';
        }
    }
    int sum = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])sum++;
    }
    cout << sum++;
}