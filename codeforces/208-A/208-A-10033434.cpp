#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string m = s;
    bool test = false;
    for (int i = 0; i < s.length(); i++)
    {
        test = false;
        if (i != s.length() - 1 || i != s.length() - 2)
        {
            if (s[i] == 'W'&&s[i + 1] == 'U'&&s[i + 2] == 'B')
            {
                cout << " ";
                i = i + 2;
                test = true;
            }
            else cout << s[i];
        }
        else cout << s[i];
    }
}