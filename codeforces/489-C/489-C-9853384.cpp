#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <stdio.h>
#include<fstream>
using namespace std;
bool test(string s, int k)
{
    int sum = 0;
    for (int i = 0; i<s.length(); i++)sum += (s[i] - 48);
    if (sum == k)return true;
    else return false;
}
int main()
{
    int m, s; cin >> m >> s; int o = s;
    if (m == 1 && s > 9)cout << "-1 -1" << endl; else
    if (m == 1 && s < 9)cout << s << " " << s << endl; else
    if (m>1 && s == 0)cout << "-1 -1" << endl; else
    if (m * 9 < s)cout << "-1 -1" << endl;else
    {
        string v; int z = 9;
        while (true)
        {
            s -= z;
            if (s < 0){ s += z; z--; }
            else if (s == 0){ v += (z + 48); break; }
            else{ v += (z + 48); }
        }
        string min = "1"; for (int i = 0; i < m - 1; i++)min.insert(1, "0"); int pos = m - 1;
        while (true)
        {
            bool f = test(min, o);
            if (f)break;
            if (min[pos] == '9')pos--;
            else min[pos] += 1;
        }
        if (v.length() == m){ string b = v; reverse(v.begin(), v.end()); cout << min << " " << b << endl; }
        else
        {
            string b = v;
            while (m != v.length()){ v += '0'; }
            cout << min << " " << v << endl;
        }
    }
}