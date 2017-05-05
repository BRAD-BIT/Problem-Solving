#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = s1;
    for (int i = 0; i < s2.length(); i++)
    {
        if ((s1[i] == '1'&&s2[i] == '1') || (s1[i] == '0'&&s2[i] == '0'))s3[i] = '0';
        else s3[i] = '1';
    }
    cout << s3;
}