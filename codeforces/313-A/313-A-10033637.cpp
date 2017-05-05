#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
/*stringstream ss;
ss << int name;
string string name = ss.str();*/
int main()
{
    int n;
    cin >> n;
    if (n > 0)cout << n;
    else
    {
        if (-n < 91 && (-n) % 10 == 0)cout << 0;
        else
        {
            stringstream ss;
            ss << n;
            string s = ss.str();
            int sum = 0;
            for (int i = 0; i < s.length() - 2; i++)
            {
                cout << s[i];
            }
            if (s[s.length() - 1]>s[s.length() - 2])cout << s[s.length() - 2];
            else cout << s[s.length() - 1];
        }
    }
}