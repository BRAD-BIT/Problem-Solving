#include<iostream>
#include<string>
using namespace std;
int main()
{
    int sum1 = 0, sum2 = 0;string s; cin >> s;
    for (int i = 0; i < s.length(); i++)if (s[i] == '4')sum1++; else if (s[i] == '7')sum2++;
    if (sum1 >= sum2&&sum1!=0)cout << 4 << endl;
    else if (sum2 >= sum1&&sum2 != 0)cout << 7 << endl;
    else cout << -1 << endl;
}