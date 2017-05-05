#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    char c;
    string s1;
    cin >> c >> s1;
    string s2 = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i] == s2[j] && c == 'R')
            {
                s1[i] = s2[j - 1];
                break;
            }
            else
            {
                if (s1[i] == s2[j] && c == 'L')
                {
                    s1[i] = s2[j + 1];
                    break;
                }
            }
        }
    }
    cout << s1;
}