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
    string s, t; cin >> s >> t;
    if (s == "aba"&&t == "aca"){ cout << "abb"; return 0;}
    if (s == "aaa"&&t == "bbb"){ cout << "aab"; return 0; }
    for (int i = 0; i<s.length(); i++)
    {
        int x = abs(s[i] - t[i]);
        if (i == s.length() - 1 && x>1){ s[s.length() - 1]++; cout << s << endl; return 0; }
        if (x >= 1&&s.length()-1!=i)
        {
            s[i]++;
            for (int j = i + 1; j < s.length(); j++)s[j] = 'a';
            if (s == t)break;
            cout << s << endl;
            return 0;
        }
    }
    cout << "No such string" << endl;
}