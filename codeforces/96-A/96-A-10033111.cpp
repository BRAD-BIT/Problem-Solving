#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sum0 = 0;
    int sum1 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            sum1 = sum1 + 1;
            sum0 = 0;
        }
        if (s[i] == '0')
        {
            sum0 = sum0 + 1;
            sum1 = 0;
        }
        if (sum0 == 7 || sum1 == 7)
        {
            cout << "YES";
            break;
        }
    }
    if (sum1 != 7 && sum0 != 7)cout << "NO";
}