#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s; cin >> s; int x = s.length();
    for (int i = 0; i < x; i++){if (s[i] % 2 == 0 && s[x - 1]>s[i]){swap(s[i], s[x - 1]); cout << s << endl; return 0;}}
    for (int i = x - 2; i >= 0; i--){ if (s[i] % 2 == 0){ swap(s[i], s[x - 1]); cout << s << endl; return 0; } }
    cout << -1 << endl;
}