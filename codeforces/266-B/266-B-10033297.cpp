#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, t;
    string s;
    cin >> n >> t >> s;
    string s2 = s;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'B'&&s[j + 1] == 'G')
            {
                s2[j] = 'G';
                s2[j + 1] = 'B';
            }
        }
        s = s2;
    }

    cout << s2;
}