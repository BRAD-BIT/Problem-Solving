#include<iostream>
#include<string>
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
    string s; cin >> s; int sum = 0, sum5 = 0;
    char x = s[0];
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] != x){ sum++; sum5 = 1; x = s[i]; }
        else
        if (sum5 == 5){ sum5 = 1; sum++; if (i == s.length())break; }
        else
        {
            sum5++;
        }
    }
    cout << sum << endl;
}