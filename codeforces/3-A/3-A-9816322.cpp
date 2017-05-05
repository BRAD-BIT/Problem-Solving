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
int main()
{
    string s, t; cin >> s >> t;
    if (s == t)cout << 0 << endl;
    else
    if (s[0] == t[0])
    {
        cout << abs(s[1] - t[1]) << endl;
        if (s[1] > t[1])for (int i = 0; i < abs(s[1] - t[1]); i++)cout << "D" << endl;
        else
        if (s[1] < t[1])for (int i = 0; i < abs(s[1] - t[1]); i++)cout << "U" << endl;
    }
    else
    if (s[1] == t[1])
    {
        cout << abs(s[0] - t[0]) << endl;
        if (s[0]>t[0])for (int i = 0; i < abs(s[0] - t[0]); i++)cout << "L" << endl;
        else
        if (s[0]<t[0])for (int i = 0; i < abs(s[0] - t[0]); i++)cout << "R" << endl;
    }
    else
    {
        if (abs(s[0] - t[0]) == abs(s[1] - t[1]))
        {
            cout << abs(s[0] - t[0]) << endl;
            if (t[0] < s[0] && t[1]<s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "LD" << endl; }
            else
            if (t[0] > s[0] && t[1]>s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "RU" << endl; }
            else
            if (t[0] < s[0] && t[1]>s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "LU" << endl; }
            else
            if (t[0] > s[0] && t[1]<s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "RD" << endl; }
        }
        else
        if (abs(s[0] - t[0]) > abs(s[1] - t[1]))
        {
            cout << abs(s[0] - t[0]) << endl;
            int z = abs(s[0] - t[0]) - abs(s[1] - t[1]);
            if (t[0] < s[0] && t[1] < s[1]){ for (int i = 0; i<abs(s[1] - t[1]); i++)cout << "LD" << endl; for (int i = 0; i<z; i++)cout << "L" << endl; }
            else
            if (t[0] > s[0] && t[1]>s[1]){ for (int i = 0; i<abs(s[1] - t[1]); i++)cout << "RU" << endl; for (int i = 0; i<z; i++)cout << "R" << endl; }
            else
            if (t[0] < s[0] && t[1]>s[1]){ for (int i = 0; i<abs(s[1] - t[1]); i++)cout << "LU" << endl; for (int i = 0; i<z; i++)cout << "L" << endl; }
            else
            if (t[0] > s[0] && t[1]<s[1]){ for (int i = 0; i<abs(s[1] - t[1]); i++)cout << "RD" << endl; for (int i = 0; i<z; i++)cout << "R" << endl; }
        }
        else
        {
            cout << abs(s[1] - t[1]) << endl;
            int z = abs(s[1] - t[1]) - abs(s[0] - t[0]);
            if (t[0] < s[0] && t[1]<s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "LD" << endl; for (int i = 0; i<z; i++)cout << "D" << endl; }
            else
            if (t[0] > s[0] && t[1]>s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "RU" << endl; for (int i = 0; i<z; i++)cout << "U" << endl; }
            else
            if (t[0] < s[0] && t[1]>s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "LU" << endl; for (int i = 0; i<z; i++)cout << "U" << endl; }
            else
            if (t[0] > s[0] && t[1]<s[1]){ for (int i = 0; i<abs(s[0] - t[0]); i++)cout << "RD" << endl; for (int i = 0; i<z; i++)cout << "D" << endl; }
        }
    }
}