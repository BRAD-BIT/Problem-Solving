#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    string s, ss, sss; cin >> s; ss = s; reverse(ss.begin(), ss.end()); sss = s;
    if (s == ss){ s.insert(s.length() / 2, 1, s[s.length()/2]); cout << s << endl; return 0; }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            s.insert(s.length() - i, 1, s[i]); break;
        }
    }
    ss = s; reverse(ss.begin(), ss.end());
    if (s == ss){ cout << s << endl; return 0; }
    for (int i = 0; i < sss.length(); i++)
    {
        if (sss[i] != sss[sss.length() - 1 - i])
        {
            sss.insert(i, 1, sss[sss.length() - 1 - i]); break;
        }
    }
    ss = sss; reverse(ss.begin(), ss.end());
    if (sss == ss){ cout << sss << endl; return 0; }
    cout << "NA" << endl;
}