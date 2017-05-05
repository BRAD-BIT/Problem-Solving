#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool fuck;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
        {
            cout << "YES";
            fuck = false;
            break;
        }
    }
    if (fuck)cout << "NO";
}