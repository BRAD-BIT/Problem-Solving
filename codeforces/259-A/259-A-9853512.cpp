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
    string s;
    for (int i = 0; i < 8; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length() - 1; j++)
        {
            if (s[j] == s[j + 1]){ cout << "NO" << endl; return false; }
        }
    }
    cout << "YES" << endl;
}