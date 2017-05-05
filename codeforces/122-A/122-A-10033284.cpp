#include<iostream>
#include<string>
#include <sstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool test = false;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            test = true;
            stringstream ss;
            ss << i;
            string s = ss.str();
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] != '7' && s[j] != '4')
                {
                    test = false;
                }
                if (!test)break;
            }
        }
        if (test)break;
    }
    if (test)cout << "YES";
    else cout << "NO";
}