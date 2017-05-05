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
    map<char, int> a;
    for (int i = 0; i < t.length(); i++)
    {
        if (a[t[i]] == 0)a[t[i]] = 1;
        else a[t[i]]++;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char d = s[i];
        if (a[d] != 0){ sum1++; a[d]--; s.erase(i, 1); i = -1;}
    }
    for (int i = 0; i < s.length(); i++)
    {
        char d = s[i];
        if (isupper(d))d += 32;
        else d -= 32;
        if (a[d] != 0){ sum2++; a[d]--;}
    }
    cout << sum1 << " " << sum2 << endl;
}