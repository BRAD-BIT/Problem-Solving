#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<functional>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
bool div_8(string s)
{
    if (stoll(s) % 8 == 0)return 1; else return 0;
}
int main()
{
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        string temp1;
        temp1 += s[i];
        if (div_8(temp1)){ cout << "YES\n"; cout << temp1 << endl; return 0; }
        for (int j = i+1; j < s.length(); j++)
        {
            string temp2;
            temp2 += s[i]; temp2 += s[j];
            if (div_8(temp2)){ cout << "YES\n"; cout << temp2 << endl; return 0; }
            for (int k = j+1; k < s.length(); k++)
            {
                string temp3;
                temp3 += s[i]; temp3 += s[j]; temp3 += s[k];
                if (div_8(temp3)){ cout << "YES\n"; cout << temp3 << endl; return 0; }
            }
        }
    }
    cout << "NO\n";
}