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
    string s;
    cin >> s;
    bool test = false;
    int p = 0;
    for (int i = 0; i < s.length()-1; i++)
    {
        if ((s[i] - 48 == 0)&&p==0)
        {
            test = true;
            p++;
        }
        else
        {
            cout << s[i];
        }
    }
    if (test)cout << s[s.length() - 1];
}