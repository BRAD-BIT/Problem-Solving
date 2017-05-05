#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s; 
    cin >> s; 
    int x = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i+1; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                x--;
                break;
            }
        }
    }
    if (x %2== 0)cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}