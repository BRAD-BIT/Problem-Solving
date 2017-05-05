#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s,s1, t; cin >> s >> t; int sum = 0; vector<string> a;
    while (s != t)
    {
        if (s[0]>t[0]){s1 += 'L';s[0]--;}
        else
        if (s[0]<t[0]){s1 += 'R';s[0]++;}
        if (s[1]>t[1]){s1 += 'D';s[1]--;}
        else
        if (s[1]<t[1]){s1 += 'U';s[1]++;}
        a.push_back(s1);s1.clear();sum++;
    }
    cout << sum << endl;
    for (int i = 0; i < a.size(); i++)cout << a[i] << endl;
}