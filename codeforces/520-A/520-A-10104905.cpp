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
    int n; cin >> n;string s; cin >> s; set<char> a;
    for (int i = 0; i < s.length(); i++)
    {
        char h = s[i];
        if (isupper(h))
        {
            h = tolower(h);
        }
        a.insert(h);
    }
    if (a.size()==26)cout << "YES"; else cout << "NO";
}