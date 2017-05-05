#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s1, s2;
    s2 = "/";
    for (int i = 0; i < n; i++)
    {
        cin >> s1;
        if (s1 == "pwd")cout << s2 << endl;
        else
        {
            cin >> s1;
            if (s1[0] == '/')
            {
                s2 = s1;
            }
            else
            {
                if (s2[s2.length() - 1] == '/')
                {
                    s2 = s2 + s1;
                }
                else
                {
                    s2 = s2 + "/" + s1;
                }
            }
            if (s2[s2.length() - 1] != '/')s2 = s2 + '/';
            int m1, m2;
            for (int v = 0; v < s2.length() - 1; v++)
            {
                if (s2[v] == '.'&&s2[v + 1] == '.')
                {
                    m1 = v + 1;
                    v = -1;
                    for (int j = m1 - 3; j >= 0; j--)
                    {
                        if (s2[j] == '/')
                        {
                            m2 = j;
                            break;
                        }
                    }
                    s2.erase(m2, m1-m2+1);
                }
            }
        }
    }
}