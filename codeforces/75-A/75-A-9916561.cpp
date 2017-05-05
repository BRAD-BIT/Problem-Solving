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
    ll a1, b1, c1;cin >> a1 >> b1; c1 = a1 + b1;
    string s1 = to_string(a1), s2 = to_string(b1), s3, s4, s5 = to_string(c1), s6;
    for (int i = 0; i < s1.length(); i++){ if (s1[i] != '0')s3 += s1[i]; }
    for (int i = 0; i < s2.length(); i++){ if (s2[i] != '0')s4 += s2[i]; }
    for (int i = 0; i < s5.length(); i++){ if (s5[i] != '0')s6 += s5[i]; }
    if (stoll(s3) + stoll(s4)==stoll(s6))cout << "YES" << endl; else cout << "NO" << endl;
}