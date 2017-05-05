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
    int k, sum = 0; cin >> k; set<char> a; char x; string s;
    for (int i = 0; i < 16; i++){ cin >> x;if(x!='.')s += x; }sort(s.begin(), s.end());
    x = s[0];
    for (int i = 0; i <= s.length(); i++)
    {
        if (x != s[i])
        {
            if (sum>k * 2){ cout << "NO" << endl; return 0;}x = s[i]; sum = 0;
        }
        sum++;
    }
    cout << "YES" << endl;      
}