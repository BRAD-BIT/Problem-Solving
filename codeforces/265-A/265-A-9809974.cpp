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
    string s, t; int pos = 0; cin >> s >> t;
    for (int i = 0; i < t.length(); i++){ if (t[i] == s[pos])pos++; }
    cout << pos + 1;
}